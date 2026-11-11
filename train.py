"""

Each forward passes should be rewarded for producing an action 
that increases the whole games score, and produces good actions later on
    - Return to go scoring: Only count the score from the current action until
    the end. The score up to the current state of the game should not have an
    impact on the reward since the forward pass had no effect on that

Simplified training flow:
1.  Run many forward passes to play through an entire game, start to finish.
    Record (state, legal actions, index of action picked) at each pass.
2.  When the game is finished, record the total score, and at each forward pass
    compute g_t = final score - prev. score, to use return to go scoring.
3.  Learn: This time, tracking gradients, run forward with the (state, legal actions),
    and get the action a_i = actions[index of action picked].
    Then backpropogate with the loss:
        loss = -log(probs[a_i]) * (g_t)
    This incentives increasing the prob of move a_i to decrease the lost.
    This is scaled by g_t so that, averaged over many training steps, moves that
    result in higher g_t get their probabilites increased more. Since probs sum
    to 1, this over time results in incenitivizing moves that result in long term scoring
"""
from Network import transformer
import math
import torch
from Engine.ffengine import FFEngine, GRID_CENTER
import torch.nn as nn
from typing import Any, Tuple
import matplotlib.pyplot as plt
from checkpoint import TrainingTracker

def lengths_to_mask(lengths, max_len: int, device: torch.device) -> torch.Tensor:
    """(B,) per-game row counts -> (B, max_len) bool mask on device, True for each game's first lengths[i] rows"""
    return (torch.arange(max_len)[None, :] < torch.from_numpy(lengths.astype("int64"))[:, None]).to(device)

def pad_batch(arrays: list, device: torch.device) -> Tuple[torch.Tensor, torch.Tensor]:
    """list of (n_i, F) arrays -> zero-padded (B, max n_i, F) tensor and its (B, max n_i) bool mask, both on device"""
    padded = nn.utils.rnn.pad_sequence([torch.from_numpy(a) for a in arrays], batch_first=True)
    lengths = torch.tensor([len(a) for a in arrays])
    return padded.to(device), (torch.arange(padded.size(1))[None, :] < lengths[:, None]).to(device)

def compute_cost(n_placed: int, n_hand: int, m: int, model: transformer.SetPointTransformer) -> float:
    """
    Estimated fwd+bwd cost of one record padded to n_placed, n_hand, m, in units of block_dim^2 multiply-adds.
    At these sizes the per-token linear layers dominate, not attention:
        each of the n = CLS + placed + hand tokens: 12 d^2 per self-attention block (W_q,k,v,o = 4 d^2, MLP = 8 d^2),
            plus 2 d^2 per score block (its W_k, W_v)
        each of the m actions: 10 d^2 per score block (W_q, W_o, MLP), plus d^2 for score_layer
        attention: 2 n^2 d per self-attention block and 2 n m d per score block (Q @ K.T and A @ V)
    Measured on mps, time and memory per unit stay within ~1.5x across n = 8..200, m = 16..5000
    (n^2 + n m was off by ~30x)
    """
    d, L, S = model.block_dim, len(model.blocks), len(model.score_blocks)
    n = n_placed + n_hand + 1
    return n * (12 * L + 2 * S) + m * (10 * S + 1) + (2 * L * n * n + 2 * S * n * m) / d

# the value head predicts g_t / VALUE_SCALE: targets around 1, not in the hundreds, so its
# output layer can reach them at small learning rates and its loss doesn't swamp the policy loss
VALUE_SCALE = 100

SHAPE_BIN_RATIO = 1.4 # measured: 1.3-1.4 minimizes epoch time (smaller = less padding, but more, smaller buckets)

def shape_bin(record) -> Tuple[int, int]:
    """
    (actions, placed) bin of a record on a log scale, each bin spanning a factor of SHAPE_BIN_RATIO.
    Placed and action counts are only loosely correlated (r ~ 0.5), so sorting by one number leaves 40-70%
    padding in a bucket; keeping each bucket inside one bin cuts it to ~15%
    """
    return (int(math.log(max(1, len(record[2]))) / math.log(SHAPE_BIN_RATIO)),
            int(math.log(max(1, len(record[0]))) / math.log(SHAPE_BIN_RATIO)))


def get_game_choices(model: nn.Module, env: FFEngine, n_target_games: int) -> Tuple[list[list[Any]], float]:
    """
    With no gradients, play through n_target_games games and collect, per each action,
    a [placed, hand, actions, action_idx, old_log_prob, compute_required, pred_g_t, reward, g_t],
    (ndarray, ndarray, ndarray, int, float, float, float, int, int)
    representing the model's forward pass
    parameters and its g_t:
        placed: The placed cubes at the current step
        hand: The cards in the hand
        actions: List of all possible actions (gpid, x, y, z, rot)
        action_idx: The index in actions that the model chose
        old_log_prob: log probability the model gave action_idx when it played this move.
            PPO compares the model's later probability for this move against it
        reward: The points this one action earned
        g_t: The return to go scoring metric; Higher means the current action
            resulted in a better overall score
        compute_required: compute_cost() estimate of this record's fwd+bwd cost
        pred_g_t: the value head's prediction of g_t when this move was played, in points
    
    """

    # the total end of game scores of all n_target_games
    # used for tracking the average score
    total_game_scores = 0

    in_progress = [[] for _ in range(env.n_games)] # one list per env slot
    finished = [] # records of every move from completed games
    n_finished_games = 0 # finished holds moves, not games, so count games separately
    device = next(model.parameters()).device
    with torch.no_grad():
        while n_finished_games < n_target_games:
            obs = env.observe()
            # batched forward pass over each game: every game is padded to this step's largest game.
            # rows past a game's count are junk left in the engine's buffers, so masks mark the real rows
            P, H, M = int(obs.n_placed.max()), int(obs.n_hand.max()), int(obs.n_actions.max())
            # copy: obs holds env's shared buffers, which the next observe() overwrites
            placed_b, hand_b, actions_b = obs.placed[:, :P].copy(), obs.hand[:, :H].copy(), obs.actions[:, :M].copy()

            # center coordinates on the city's start, so x, y, z are small numbers around 0
            # instead of ~500, which would swamp the 0/1 features. done once here, so the
            # stored records (used again in the learning phase) are centered too
            placed_b[..., 0:3] -= GRID_CENTER   # placed: [x, y, z, bits...]
            actions_b[..., 1:4] -= GRID_CENTER  # actions: [gp_id, x, y, z, rot]

            log_probs, preds = model.forward(torch.from_numpy(placed_b).to(device), lengths_to_mask(obs.n_placed, P, device),
                                      torch.from_numpy(hand_b).to(device), lengths_to_mask(obs.n_hand, H, device),
                                      torch.from_numpy(actions_b).to(device), lengths_to_mask(obs.n_actions, M, device)) # (n_games, M), (n_games,)
            log_probs, preds = log_probs.cpu(), preds.cpu()
            # .cpu(): one copy back per step, so sampling and the per-game .item() calls don't each wait on the GPU
            indicies = torch.multinomial(log_probs.exp(), 1).squeeze(1).tolist() # one sampled action per game

            # collect actions for each game
            for i in range(env.n_games):
                # store only game i's real rows, unpadded. copy, so the record doesn't keep the whole padded batch alive
                placed = placed_b[i, :obs.n_placed[i]].copy()
                hand = hand_b[i, :obs.n_hand[i]].copy()
                actions = actions_b[i, :obs.n_actions[i]].copy()
                action_idx = indicies[i]
                # PPO: remember how likely the model thought this move was when it played it
                old_log_prob = log_probs[i, action_idx].item()

                # estimate of the compute required for this action, used to sort records into buckets
                compute_required = compute_cost(len(placed), len(hand), len(actions), model)
                
                in_progress[i].append([placed, hand, actions, action_idx, old_log_prob, compute_required, preds[i].item() * VALUE_SCALE])

            # For each game remaining, compute the rewards
            rewards, dones, final_scores = env.step(indicies)
            for i in range(env.n_games):
                # this step's reward belongs to the record just added for game i
                in_progress[i][-1].append(int(rewards[i]))

                if dones[i]:
                    total_game_scores += final_scores[i]
                    # return to go: walk the game backwards, keeping a running sum of rewards
                    g = 0
                    for record in reversed(in_progress[i]):
                        g += record[7]          # record = [placed, hand, actions, action_idx, old_log_prob, compute_required, pred_g_t, reward]
                        record.append(g)        # now [placed, hand, actions, action_idx, old_log_prob, compute_required, pred_g_t, reward, g_t]
                    finished.extend(in_progress[i])
                    n_finished_games += 1
                    in_progress[i] = []         # a new game already started in this slot
    return (finished, total_game_scores / n_finished_games)


def train():
    torch.set_num_threads(1) # measured for empirical speedup
    device = torch.device("mps" if torch.backends.mps.is_available() else "cpu") # mps: Apple GPU, ~4-5x faster here
    
    # init model & env
    model = transformer.SetPointTransformer(256, 7) # smallish network for now
    model.to(device) # before creating the optimizer, so its state lives on the same device
    n_games = 16
    env = FFEngine(n_games, seed = 0)
    num_update_steps = 10000
    games_played_per_update_step = 60
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-4)
    B = 0.01
    n_epochs = 4      # PPO: update passes over each batch of games, instead of 1
    clip_eps = 0.2    # PPO: each move's probability may move at most ~20% per batch
    value_coef = 0.5  # weight of the value head's loss against the policy loss

    # max compute_cost() of one padded bucket. memory on mps is ~1.3-2.1 GB per 1M units
    scaled_compute_budget = 1000000 # measured: the gpu saturates at ~0.5-1M per bucket, bigger only adds padding (~5 GB peak)

    # live plot of the average final game score per update step. ion() = interactive mode, so the
    # window redraws during training instead of blocking until the end
    score_history = []
    plt.ion()
    fig, ax = plt.subplots()
    ax.set_xlabel("update step")
    ax.set_ylabel("average final score")
    (score_line,) = ax.plot([], [])

    tracker = TrainingTracker() # saves best.pt, 10% milestones, log.csv and scores.png under runs/

    for step in range(num_update_steps):
        forward_results, average_score = get_game_choices(model, env, games_played_per_update_step)
        # advantage of each move: g_t - pred_g_t. Normalized over the whole batch, so the policy loss
        # stays around +-1 whatever the score scale
        advantages = torch.tensor([r[8] - r[6] for r in forward_results], dtype = torch.float)
        adv_mean, adv_std = advantages.mean().item(), advantages.std().item()

        # maximize compute by sorting forward_results into buckets with similar size tokens, so that
        # padding is similar size and there aren't early game (10+ tok) and late games (10k+ tok)
        # mixed together, since that would waste most compute on padding

        # sort by shape bin, then compute required
        forward_results.sort(key = lambda res: (shape_bin(res), res[5]))

        # maximize compute by sorting into buckets where each bucket is the max
        # that can be batched at once
        
        # sort each game-action pair from forward_results into buckets,
        # each taking the max amount of compute less than scaled_compute_budget
        # We batch over buckets so that each bucket has the max number of tokens it can handle
        buckets = [[]]
        bucket_i = 0
        P = H = M = 0 # the current bucket's padded sizes
        for res in forward_results:
            # because of padding, every element in a bucket costs the same: pad_batch pads placed, hand
            # and actions each to their own max over the bucket, so a bucket costs
            # len(bucket) * compute_cost(max placed, max hand, max actions)
            p, h, m = max(P, len(res[0])), max(H, len(res[1])), max(M, len(res[2]))
            # start a new bucket at each new shape bin, or when the padded bucket would go over budget
            if buckets[bucket_i] and (shape_bin(res) != shape_bin(buckets[bucket_i][-1])
                                      or (len(buckets[bucket_i]) + 1) * compute_cost(p, h, m, model) > scaled_compute_budget):
                bucket_i += 1
                buckets.append([])
                p, h, m = len(res[0]), len(res[1]), len(res[2])
            P, H, M = p, h, m
            buckets[bucket_i].append(res)


        # wrap in n_epochs to allow for PPO updating, capping the amount that
        # probailities shift to 20% with each gameplay batch
        for _ in range(n_epochs):
            optimizer.zero_grad()

            # average gradients
            for bucket in buckets:
                if not bucket:
                    continue # edge case: a single record over budget leaves the first bucket empty
                placed, placed_mask = pad_batch([r[0] for r in bucket], device)
                hand, hand_mask = pad_batch([r[1] for r in bucket], device)
                actions, actions_mask = pad_batch([r[2] for r in bucket], device)
                log_probs, cur_pred = model.forward(placed, placed_mask, hand, hand_mask, actions, actions_mask) # (b, M)


                # g_t := difference from current action to end game score.
                # One way to train is (g_t - end score), but that puts early actions at >100
                # and late actions at <10. Thats not a good signal for the model
                # instead we train with (g_t - pred_g_t), where the model also learns to predict the
                # predicted g_t at this point. If (g_t - pred_g_t) is high, that means the
                # move was a better move than normal
                g_t_diff = (torch.tensor([r[8] - r[6] for r in bucket], dtype=torch.float, device=device) - adv_mean) / (adv_std + 1e-8)

                # entropy loss: incenitivze not being too confident around one decision
                # padded actions have log prob -inf; zero them so 0 * -inf doesn't give nan
                entropy = -(log_probs.exp() * log_probs.masked_fill(~actions_mask, 0)).sum(dim=-1)

                # PPO: how much more (or less) likely this move is now than when it was played.
                # the model's current log prob of the move it played in each row (r[3] is its index)
                new_prob = log_probs[torch.arange(len(bucket), device=device), torch.tensor([r[3] for r in bucket], device=device)]
                old_prob = torch.tensor([r[4] for r in bucket], device=device)
                ratio = torch.exp(new_prob - old_prob) # ratio = new_prob / old_prob, done w/ exponent div

                # the same ratio, but kept between 0.8 and 1.2
                clipped_ratio = torch.clamp(ratio, 1 - clip_eps, 1 + clip_eps)

                """
                over n_epochs, if the probailities increase more than 20%,
                we don't let it update any further. It can jump over 20 once,
                but then no further.

                Once the ratio of new vs old probability is more than 20%, we cap it to 20,
                so that the policy loss reflects at most a soft capped 20% increase in
                probabilities. Once the ratio passes the limit in the direction g_t_diff
                pushes it, min() picks the clipped term, which is a constant, so it zeros
                the gradient and stops this move from being optimized further
                """
                policy_loss = -torch.min(ratio * g_t_diff, clipped_ratio * g_t_diff)

                # pred learns to match the g_t's in bucket (in units of VALUE_SCALE points)
                pred_loss = torch.square(cur_pred - torch.tensor([r[8] for r in bucket], dtype=torch.float, device=device) / VALUE_SCALE)
                
                cur_loss = policy_loss - B * entropy + value_coef * pred_loss


                (cur_loss.sum() / len(forward_results)).backward() # compute averaged gradients

            # step based on average gradients
            optimizer.step()

        # mps keeps freed buffers cached in host-shared memory; without this the process grows ~1.5 GB per update
        if device.type == "mps": torch.mps.empty_cache()

        # update the plot
        score_history.append(average_score)
        score_line.set_data(range(len(score_history)), score_history)
        ax.relim()
        ax.autoscale_view()
        plt.pause(0.01) # lets the window redraw
        tracker.update(step, average_score, model)


if __name__ == "__main__":
    train()
