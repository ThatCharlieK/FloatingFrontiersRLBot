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
import torch
from Engine.ffengine import FFEngine, GRID_CENTER
import torch.nn as nn
from typing import Any, Tuple
import matplotlib.pyplot as plt
from checkpoint import TrainingTracker

def lengths_to_mask(lengths, max_len: int) -> torch.Tensor:
    """(B,) per-game row counts -> (B, max_len) bool mask, True for each game's first lengths[i] rows"""
    return torch.arange(max_len)[None, :] < torch.from_numpy(lengths.astype("int64"))[:, None]

def pad_batch(arrays: list) -> Tuple[torch.Tensor, torch.Tensor]:
    """list of (n_i, F) arrays -> zero-padded (B, max n_i, F) tensor and its (B, max n_i) bool mask"""
    padded = nn.utils.rnn.pad_sequence([torch.from_numpy(a) for a in arrays], batch_first=True)
    lengths = torch.tensor([len(a) for a in arrays])
    return padded, torch.arange(padded.size(1))[None, :] < lengths[:, None]


def get_game_choices(model: nn.Module, env: FFEngine, n_target_games: int) -> Tuple[list[list[Any]], float]:
    """
    With no gradients, play through n_target_games games and collect, per each action,
    a [placed, hand, actions, action_idx, old_log_prob, compute_required, reward, g_t],
    (ndarray, ndarray, ndarray, int, float, int, int, int)
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
        compute_required: int estimate n^2 + m * n of this record's attention cost (n = CLS + placed + hand, m = actions)
    
    """

    # the total end of game scores of all n_target_games
    # used for tracking the average score
    total_game_scores = 0

    in_progress = [[] for _ in range(env.n_games)] # one list per env slot
    finished = [] # records of every move from completed games
    n_finished_games = 0 # finished holds moves, not games, so count games separately
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

            log_probs = model.forward(torch.from_numpy(placed_b), lengths_to_mask(obs.n_placed, P),
                                      torch.from_numpy(hand_b), lengths_to_mask(obs.n_hand, H),
                                      torch.from_numpy(actions_b), lengths_to_mask(obs.n_actions, M)) # (n_games, M)
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

                # estimate of the compute required for this action:
                # where compute = b * (n^2 + m * n) for b batches, n tokens, m actions
                n_tok = len(placed) + len(hand) + 1 # number of non-action tokens, +1 for CLS
                compute_required = n_tok ** 2 + n_tok * len(actions)
                
                in_progress[i].append([placed, hand, actions, action_idx, old_log_prob, compute_required])

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
                        g += record[6]          # record = [placed, hand, actions, action_idx, old_log_prob, compute_required, reward]
                        record.append(g)        # now [placed, hand, actions, action_idx, old_log_prob, compute_required, reward, g_t]
                    finished.extend(in_progress[i])
                    n_finished_games += 1
                    in_progress[i] = []         # a new game already started in this slot
    return (finished, total_game_scores / n_finished_games)


def train():
    torch.set_num_threads(1) # measured for empirical speedup
    
    # init model & env
    model = transformer.SetPointTransformer(256, 7) # smallish network for now
    n_games = 16
    env = FFEngine(n_games, seed = 0)
    num_update_steps = 10000
    games_played_per_update_step = 30
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-4)
    B = 0.01
    n_epochs = 4      # PPO: update passes over each batch of games, instead of 1
    clip_eps = 0.2    # PPO: each move's probability may move at most ~20% per batch

    # rough budget for number of tokens this machine can handle in a single batch
    # instead of computing raw tokens we max it as a scaled_compute_budget, since compute roughly
    # scales with n_tokens^2 in attention
    scaled_compute_budget = 3000000

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
        g_t_average = sum(result[7] for result in forward_results) / len(forward_results)
        g_t_std = torch.tensor([r[7] for r in forward_results], dtype = torch.float).std()

        # maximize compute by sorting forward_results into buckets with similar size tokens, so that
        # padding is similar size and there aren't early game (10+ tok) and late games (10k+ tok)
        # mixed together, since that would waste most compute on padding

        # sort by compute required
        forward_results.sort(key = lambda res: res[5])

        # maximize compute by sorting into buckets where each bucket is the max
        # that can be batched at once
        
        # sort each game-action pair from forward_results into buckets,
        # each taking the max amount of compute less than scaled_compute_budget
        # We batch over buckets so that each bucket has the max number of tokens it can handle
        buckets = [[]]
        bucket_i = 0
        for res in forward_results:
            # because of padding, the compute for each element per bucket is the same,
            # since everything in a given bucket is padded to the same length
            # thus since forward_results is sorted, the compute for a bucket is the 
            # compute for highest res * num elements in that bucket
            if (len(buckets[bucket_i]) + 1) * res[5] > scaled_compute_budget:
                bucket_i += 1
                buckets.append([])
            buckets[bucket_i].append(res)


        # wrap in n_epochs to allow for PPO updating, capping the amount that
        # probailities shift to 20% with each gameplay batch
        for _ in range(n_epochs):
            optimizer.zero_grad()

            # average gradients
            for bucket in buckets:
                if not bucket:
                    continue # edge case: a single record over budget leaves the first bucket empty
                placed, placed_mask = pad_batch([r[0] for r in bucket])
                hand, hand_mask = pad_batch([r[1] for r in bucket])
                actions, actions_mask = pad_batch([r[2] for r in bucket])
                log_probs = model.forward(placed, placed_mask, hand, hand_mask, actions, actions_mask) # (b, M)

                # subtract by the average gt so instead of all moves being increased,
                # we increase moves that are better than average, and decrease less than average
                # also normalize so good early g_t scores have the same relatively good scores later on
                g_t_normalized = (torch.tensor([r[7] for r in bucket], dtype=torch.float) - g_t_average) / (g_t_std + 1e-8)

                # entropy loss: incenitivze not being too confident around one decision
                # padded actions have log prob -inf; zero them so 0 * -inf doesn't give nan
                entropy = -(log_probs.exp() * log_probs.masked_fill(~actions_mask, 0)).sum(dim=-1)

                # PPO: how much more (or less) likely this move is now than when it was played.
                # the model's current log prob of the move it played in each row (r[3] is its index)
                new_prob = log_probs[torch.arange(len(bucket)), torch.tensor([r[3] for r in bucket])]
                old_prob = torch.tensor([r[4] for r in bucket])
                ratio = torch.exp(new_prob - old_prob) # ratio = new_prob / old_prob, done w/ exponent div

                # the same ratio, but kept between 0.8 and 1.2
                clipped_ratio = torch.clamp(ratio, 1 - clip_eps, 1 + clip_eps)

                """
                over n_epochs, if the probailities increase more than 20%,
                we don't let it update any further. It can jump over 20 once,
                but then no further.

                Once the ratio of new vs old probability is more than 20%, we cap it to 20,
                so that the policy loss reflects at most a soft capped 20% increase in
                probabilities. Once the ratio passes the limit in the direction g_t_normalized
                pushes it, min() picks the clipped term, which is a constant, so it zeros
                the gradient and stops this move from being optimized further
                """
                policy_loss = -torch.min(ratio * g_t_normalized, clipped_ratio * g_t_normalized)

                cur_loss = policy_loss - B * entropy
                (cur_loss.sum() / len(forward_results)).backward() # compute averaged gradients

            # step based on average gradients
            optimizer.step()

        # update the plot
        score_history.append(average_score)
        score_line.set_data(range(len(score_history)), score_history)
        ax.relim()
        ax.autoscale_view()
        plt.pause(0.01) # lets the window redraw
        tracker.update(step, average_score, model)


if __name__ == "__main__":
    train()
