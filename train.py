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

def get_game_choices(model: nn.Module, env: FFEngine, n_target_games: int) -> Tuple[list[list[Any]], float]:
    """
    With no gradients, play through n_target_games games and collect, per each action,
    a [placed, hand, actions, action_idx, old_log_prob, reward, g_t],
    (ndarray, ndarray, ndarray, int, float, int, int)
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
    
    """

    # the total end of game scores of all n_target_games
    # used for tracking the average score
    total_game_scores = 0

    # for now, loop over each game; add batching later
    in_progress = [[] for _ in range(env.n_games)] # one list per env slot
    finished = [] # records of every move from completed games
    n_finished_games = 0 # finished holds moves, not games, so count games separately
    with torch.no_grad():
        while n_finished_games < n_target_games:
            obs = env.observe()
            indicies = []
            # collect actions for each game
            for i in range(env.n_games):
                # copy: obs.game() returns views into env's shared buffers, which the next observe() overwrites
                placed, hand, actions = (x.copy() for x in obs.game(i))

                # center coordinates on the city's start, so x, y, z are small numbers around 0
                # instead of ~500, which would swamp the 0/1 features. done once here, so the
                # stored records (used again in the learning phase) are centered too
                placed[:, 0:3] -= GRID_CENTER   # placed: [x, y, z, bits...]
                actions[:, 1:4] -= GRID_CENTER  # actions: [gp_id, x, y, z, rot]

                log_probs = model.forward(torch.from_numpy(placed), torch.from_numpy(hand), torch.from_numpy(actions))
                action_idx = torch.multinomial(log_probs.exp(), 1).item()
                # PPO: remember how likely the model thought this move was when it played it
                old_log_prob = log_probs[action_idx].item()
                in_progress[i].append([placed, hand, actions, action_idx, old_log_prob])
                indicies.append(action_idx)

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
                        g += record[5]          # record = [placed, hand, actions, action_idx, old_log_prob, reward]
                        record.append(g)        # now [placed, hand, actions, action_idx, old_log_prob, reward, g_t]
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

    # live plot of the average final game score per update step. ion() = interactive mode, so the
    # window redraws during training instead of blocking until the end
    score_history = []
    plt.ion()
    fig, ax = plt.subplots()
    ax.set_xlabel("update step")
    ax.set_ylabel("average final score")
    (score_line,) = ax.plot([], [])

    for _ in range(num_update_steps):
        forward_results, average_score = get_game_choices(model, env, games_played_per_update_step)
        g_t_average = sum(result[6] for result in forward_results) / len(forward_results)
        g_t_std = torch.tensor([r[6] for r in forward_results], dtype = torch.float).std()

        # wrap in n_epochs to allow for PPO updating, capping the amount that
        # probailities shift to 20% with each gameplay batch
        for _ in range(n_epochs):
            optimizer.zero_grad()

            # average gradients
            for result in forward_results:
                log_probs = model.forward(torch.from_numpy(result[0]), torch.from_numpy(result[1]), torch.from_numpy(result[2]))

                # subtract by the average gt so instead of all moves being increased,
                # we increase moves that are better than average, and decrease less than average
                # also normalize so good early g_t scores have the same relatively good scores later on
                g_t_normalized = (result[6] - g_t_average) / (g_t_std + 1e-8)

                # entropy loss: incenitivze not being too confident around one decision
                entropy = -(log_probs.exp() * log_probs).sum()

                # PPO: how much more (or less) likely this move is now than when it was played.
                new_prob = log_probs[result[3]] # the model's current log prob of the move it played (result[3] is its index)
                old_prob = result[4]
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
                (cur_loss / len(forward_results)).backward() # compute averaged gradients

            # step based on average gradients
            optimizer.step()

        # update the plot
        score_history.append(average_score)
        score_line.set_data(range(len(score_history)), score_history)
        ax.relim()
        ax.autoscale_view()
        plt.pause(0.01) # lets the window redraw


if __name__ == "__main__":
    train()
