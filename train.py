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
from Engine.ffengine import FFEngine, Observation
import torch.nn as nn
from typing import NamedTuple, Tuple
import matplotlib.pyplot as plt
from checkpoint import TrainingTracker
from dataclasses import dataclass, field
import numpy as np

 # max compute_cost() of one padded bucket. memory on mps is ~1.3-2.1 GB per 1M units
SCALED_COMPUTE_BUDGET = 1000000 # measured: the gpu saturates at ~0.5-1M per bucket, bigger only adds padding (~5 GB peak)
LAMBDA = 0.9 # GAE: how fast later moves' surprises fade from a move's advantage (1 = reward_to_go - pred, 0 = TD error only). no discount (gamma = 1)

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
        each of the n = CLS + global features + placed + hand tokens: 12 d^2 per self-attention block (W_q,k,v,o = 4 d^2, MLP = 8 d^2),
            plus 2 d^2 per score block (its W_k, W_v)
        each of the m actions: 10 d^2 per score block (W_q, W_o, MLP), plus d^2 for score_layer
        attention: 2 n^2 d per self-attention block and 2 n m d per score block (Q @ K.T and A @ V)
    Measured on mps, time and memory per unit stay within ~1.5x across n = 8..200, m = 16..5000
    (n^2 + n m was off by ~30x)
    """
    d, L, S = model.block_dim, len(model.blocks), len(model.score_blocks)
    n = n_placed + n_hand + 2
    return n * (12 * L + 2 * S) + m * (10 * S + 1) + (2 * L * n * n + 2 * S * n * m) / d

# the value head predicts g_t / VALUE_SCALE: targets around 1, not in the hundreds, so its
# output layer can reach them at small learning rates and its loss doesn't swamp the policy loss
VALUE_SCALE = 100

def global_features(obs: Observation) -> np.ndarray:
    """
    (B, 3) float32 [score, points until next level, level index] of every game, scaled to small numbers
    so they don't swamp the model's global features token (scores run into the hundreds, gaps into the tens)
    """
    return np.stack([obs.scores / 100,
                     (obs.threshold_next - obs.scores) / 10,
                     obs.levels / 10], axis=1).astype(np.float32)

SHAPE_BIN_RATIO = 1.4 # measured: 1.3-1.4 minimizes epoch time (smaller = less padding, but more, smaller buckets)

def shape_bin(record: "forward_pass_result") -> Tuple[int, int]:
    """
    (actions, placed) bin of a record on a log scale, each bin spanning a factor of SHAPE_BIN_RATIO.
    Placed and action counts are only loosely correlated (r ~ 0.5), so sorting by one number leaves 40-70%
    padding in a bucket; keeping each bucket inside one bin cuts it to ~15%
    """
    return (int(math.log(max(1, len(record.actions))) / math.log(SHAPE_BIN_RATIO)),
            int(math.log(max(1, len(record.placed))) / math.log(SHAPE_BIN_RATIO)))

# data class for game choice
@dataclass
class forward_pass_result:
    """
    Holds the data for a single forward pass: 
    all the inputs at the state the model was called and the model's outputs
    
    :param placed: The placed cubes at the current state
    :param hand: The cards in the player's hand
    :param actions: All actions available to play
    :param action_idx: The action the model chose
    :param log_prob: The log probability the model gave action_idx
    :param immediate_reward: The immediate point value gained from placing that action
    :param reward_to_go: Score at end of game - score at current state
    :param pred_reward_to_go: A predicted reward_to_go that the model predicts for this action
    :param advantage: GAE advantage: TD errors of this and later moves, faded by LAMBDA
    :param compute_required: An estimate of the compute required to run this forward pass
    :param global_feats: global_features() of this state, (3,)
    """
    placed: np.ndarray
    hand: np.ndarray
    actions: np.ndarray
    action_idx: int
    log_prob: float
    immediate_reward: int
    reward_to_go: int
    pred_reward_to_go: float
    advantage: float
    compute_required: float
    global_feats: np.ndarray

class ModelInputs(NamedTuple):
    """A batch of states as the model takes them: model(*inputs). Each mask is True on a game's real rows"""
    placed: torch.Tensor
    placed_mask: torch.Tensor
    hand: torch.Tensor
    hand_mask: torch.Tensor
    actions: torch.Tensor
    actions_mask: torch.Tensor
    global_feats: torch.Tensor  # (B, 3), see global_features()

def get_batch_state_from_obs(obs: Observation, device: torch.device) -> ModelInputs:
    """
    From a observation state, get the
    [placed, placed_mask, hand, hand_mask, actions, action_mask, global_feats]
    that the model needs
    
    :param obs: Observation state from the enviornment
    :param device: where to put the tensors (the model's device)
    """

    # batched forward pass over each game: every game is padded to this step's largest game.
    # rows past a game's count are junk, so masks mark the real rows
    raw_placed_batch, raw_hand_batch, raw_actions_batch = obs.trimmed()
    placed = torch.from_numpy(raw_placed_batch).to(device)
    placed_mask = lengths_to_mask(obs.n_placed, raw_placed_batch.shape[1], device)
    hand = torch.from_numpy(raw_hand_batch).to(device)
    hand_mask = lengths_to_mask(obs.n_hand, raw_hand_batch.shape[1], device)
    raw_actions_batch[..., 5] /= 10  # points this move would score now (usually 0-20), scaled like the global features
    actions = torch.from_numpy(raw_actions_batch).to(device)
    actions_mask = lengths_to_mask(obs.n_actions, raw_actions_batch.shape[1], device)
    global_feats = torch.from_numpy(global_features(obs)).to(device)

    return ModelInputs(placed, placed_mask, hand, hand_mask, actions, actions_mask, global_feats)


def get_batch_state_from_records(records: list[forward_pass_result], device: torch.device) -> ModelInputs:
    """
    The learning phase's counterpart of get_batch_state_from_obs: from stored records, get the
    [placed, placed_mask, hand, hand_mask, actions, action_mask, global_feats]
    that the model needs, each zero-padded to the largest record in the list

    :param records: the forward_pass_results to batch, e.g. one bucket
    :param device: where to put the tensors (the model's device)
    """
    placed, placed_mask = pad_batch([r.placed for r in records], device)
    hand, hand_mask = pad_batch([r.hand for r in records], device)
    actions, actions_mask = pad_batch([r.actions for r in records], device)
    actions[..., 5] /= 10  # same points scaling as get_batch_state_from_obs (records store raw points)
    global_feats = torch.from_numpy(np.stack([r.global_feats for r in records])).to(device)

    return ModelInputs(placed, placed_mask, hand, hand_mask, actions, actions_mask, global_feats)


def get_game_choices(model: transformer.SetPointTransformer, env: FFEngine, n_target_games: int) -> Tuple[list[forward_pass_result], float]:
    """
    With no gradients, play through n_target_games games and collect,
    per each action, a forward_pass_result
    """

    # the total end of game scores of all n_target_games
    # used for tracking the average score
    total_game_scores = 0

    in_progress: list[list[forward_pass_result]] = [[] for _ in range(env.n_games)] # one list per env slot
    finished: list[forward_pass_result] = [] # records of every move from completed games
    n_finished_games = 0 # finished holds moves, not games, so count games separately
    device = next(model.parameters()).device
    with torch.no_grad():
        while n_finished_games < n_target_games:
            obs = env.observe()

            # get the state parameters from the engine
            state_params = get_batch_state_from_obs(obs, device)
            log_probs, preds = model.forward(*state_params)
            global_b = global_features(obs) # numpy copy for the records (state_params' copy is on the GPU)
            log_probs, preds = log_probs.cpu(), preds.cpu()

            # .cpu(): one copy back per step, so sampling and the per-game .item() calls don't each wait on the GPU
            indicies = torch.multinomial(log_probs.exp(), 1).squeeze(1).tolist() # one sampled action per game

            # for each game state, build a forward_pass_result
            # based on the action the model chose
            for i in range(env.n_games):
                # store only game i's real rows, unpadded. copy, since the next observe() overwrites them
                placed, hand, actions = obs.game(i, copy=True)
                action_idx = indicies[i]
                # PPO: remember how likely the model thought this move was when it played it
                old_log_prob = log_probs[i, action_idx].item()

                # estimate of the compute required for this action, used to sort records into buckets
                compute_required = compute_cost(len(placed), len(hand), len(actions), model)
                # immediate_reward and reward_to_go aren't known yet: filled in after env.step / when the game ends
                in_progress[i].append(forward_pass_result(placed, hand, actions, action_idx, old_log_prob,
                                                          immediate_reward=0, reward_to_go=0, advantage=0,
                                                          pred_reward_to_go=preds[i].item() * VALUE_SCALE,
                                                          compute_required=compute_required,
                                                          global_feats=global_b[i]))

            # For each game remaining, compute the rewards
            rewards, dones, final_scores = env.step(indicies)
            for i in range(env.n_games):
                # this step's reward belongs to the record just added for game i
                in_progress[i][-1].immediate_reward = int(rewards[i])

                if dones[i]:
                    total_game_scores += final_scores[i]
                    # walk the game backwards, keeping running sums:
                    #   g: return to go, the sum of rewards from this move on
                    #   gae: this move's TD error + LAMBDA * the next move's gae, so the next move's surprise counts LAMBDA,
                    #        the one after LAMBDA^2, ... (one pass instead of re-summing the rest of the game per move)
                    # next_pred is V(s_t+1), the value head's prediction at the next state; 0 after the last move
                    g, gae, next_pred = 0, 0.0, 0.0
                    for record in reversed(in_progress[i]):
                        g += record.immediate_reward
                        record.reward_to_go = g
                        td_error = record.immediate_reward + next_pred - record.pred_reward_to_go
                        gae = td_error + LAMBDA * gae
                        record.advantage = gae
                        next_pred = record.pred_reward_to_go
                    finished.extend(in_progress[i])
                    n_finished_games += 1
                    in_progress[i] = []         # a new game already started in this slot
    return (finished, total_game_scores / n_finished_games)

def sort_into_compute_buckets(forward_results: list[forward_pass_result], model: transformer.SetPointTransformer) -> list[list[forward_pass_result]]:
    """
    maximize compute by sorting forward_results into buckets with similar size tokens, so that
    padding is similar size and there aren't early game (10+ tok) and late games (10k+ tok)
    mixed together, since that would waste most compute on padding

    """
    # sort by shape bin, then compute required
    forward_results.sort(key = lambda res: (shape_bin(res), res.compute_required))
    # maximize compute by sorting into buckets where each bucket is the max
    # that can be batched at once
    
    # sort each game-action pair from forward_results into buckets,
    # each taking the max amount of compute less than scaled_compute_budget
    # We batch over buckets so that each bucket has the max number of tokens it can handle
    buckets: list[list[forward_pass_result]] = [[]]
    bucket_i = 0
    P = H = M = 0 # the current bucket's padded sizes
    for res in forward_results:
        # because of padding, every element in a bucket costs the same: pad_batch pads placed, hand
        # and actions each to their own max over the bucket, so a bucket costs
        # len(bucket) * compute_cost(max placed, max hand, max actions)
        p, h, m = max(P, len(res.placed)), max(H, len(res.hand)), max(M, len(res.actions))
        # start a new bucket at each new shape bin, or when the padded bucket would go over budget
        if buckets[bucket_i] and (shape_bin(res) != shape_bin(buckets[bucket_i][-1])
                                    or (len(buckets[bucket_i]) + 1) * compute_cost(p, h, m, model) > SCALED_COMPUTE_BUDGET):
            bucket_i += 1
            buckets.append([])
            p, h, m = len(res.placed), len(res.hand), len(res.actions)
        P, H, M = p, h, m
        buckets[bucket_i].append(res)
    return buckets

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
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-4) # from scratch; target_kl keeps single updates from swinging the policy
    B = 0.01
    n_epochs = 4      # PPO: update passes over each batch of games, instead of 1
    clip_eps = 0.2    # PPO: each move's probability may move at most ~20% per batch
    target_kl = 0.02  # PPO: stop this batch's epochs early once the policy has moved this far from the one that played
    value_coef = 0.5  # weight of the value head's loss against the policy loss

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
        # advantage of each move (GAE, see get_game_choices). Normalized over the whole batch, so the policy loss
        # stays around +-1 whatever the score scale
        advantages = torch.tensor([r.advantage for r in forward_results], dtype = torch.float)
        adv_mean, adv_std = advantages.mean().item(), advantages.std().item()

        buckets = sort_into_compute_buckets(forward_results, model)

        # wrap in n_epochs to allow for PPO updating, capping the amount that
        # probailities shift to 20% with each gameplay batch
        for epoch in range(n_epochs):
            optimizer.zero_grad()
            approx_kl = 0.0 # mean (old log prob - new log prob) of the played moves: how far the policy has moved

            # average gradients
            for bucket in buckets:
                if not bucket:
                    continue # edge case: a single record over budget leaves the first bucket empty
                inputs = get_batch_state_from_records(bucket, device)
                log_probs, cur_pred = model.forward(*inputs) # (b, M)

                """
                Use g_t prediction for better reward:

                reward_to_go := difference from current action to end game score.
                One way to train is (reward_to_go - end score), but that puts early actions at >100
                and late actions at <10. Thats not a good signal for the model
                instead we train with (reward_to_go - pred_reward_to_go), where the model also learns to predict the
                predicted g_t at this point. If (reward_to_go - pred_reward_to_go) is high, that means the
                move was a better move than normal

                Also use gae for even better g_t:
                (reward_to_go - pred_reward_to_go) fixes the high vs low disparity, but reward_to_go
                still is noisey since reward_to_go includes blunders and mistakes from later in the game.

                To fix, let compute the prediction at the current state, and at the current state s_t,
                and at s_t+1, which is the state after the current action, and compute:
                TD_error = reward + (next_pred_reward_to_go - pred_reward_to_go)
                
                Ex: if next_pred_reward_to_go is 310, and pred_reward_to_go is 300, and the action, reward, scored 4 pints, 
                then the action placed generated 10 + 4 = 14 more points than expected. TD_error is then a better indicator

                Except don't use this approach fully, instead, fade it out

                """
                g_t_diff = (torch.tensor([r.advantage for r in bucket], dtype=torch.float, device=device) - adv_mean) / (adv_std + 1e-8)

                # entropy loss: incenitivze not being too confident around one decision
                # padded actions have log prob -inf; zero them so 0 * -inf doesn't give nan
                entropy = -(log_probs.exp() * log_probs.masked_fill(~inputs.actions_mask, 0)).sum(dim=-1)

                # PPO: how much more (or less) likely this move is now than when it was played.
                # the model's current log prob of the move it played in each row (r.action_idx is its index)
                new_prob = log_probs[torch.arange(len(bucket), device=device), torch.tensor([r.action_idx for r in bucket], device=device)]
                old_prob = torch.tensor([r.log_prob for r in bucket], device=device)
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
                pred_loss = torch.square(cur_pred - torch.tensor([r.reward_to_go for r in bucket], dtype=torch.float, device=device) / VALUE_SCALE)
                
                cur_loss = policy_loss - B * entropy + value_coef * pred_loss

                approx_kl += (old_prob - new_prob).sum().item() / len(forward_results)

                (cur_loss.sum() / len(forward_results)).backward() # compute averaged gradients

            # the clip alone can't stop a big jump, since it only acts on moves already past 20%
            if approx_kl > target_kl:
                break

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
