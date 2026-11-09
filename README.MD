# ABOUT
Floating Frontiers RL bot is trained to play [Floating Frontiers](https://store.steampowered.com/app/4034080/Floating_Frontiers/), A city building strategy game I developed.
- Trained in a fast C RL enviornment 1:1 replica of the real game logic
- Set point transformer achitecture, generates score all valid actions and picks highest one
- 7M parameter network trained locally on M4 Macbook pro

# The RL enviornment
`/Engine` is a fast replica of floating frontiers logic, written in C. The real game has four maps, but for now the bot only plays the first map, which has simpler rules.


# Set pointer transformer
The bot is a set pointer transformer. The game state is represented as three data types:
1) `X_placed`: Cubes on the board are unordered tokens, inputed as `[cube_id, x, y, z, rot]`
2) `X_hand`: Gamepieces in hand are unordered tokens, inputed as `[gamepieceID]`
3) `Y_actions`: The ~20k enumeration of all possible valid actions is `[GamepieceID, x, y, z, rot]` action. The model outputs a choice of one of these actions

The flow is:
1) Concatenate `X_placed` and `X_hand` into one `X`, a list of n tokens, some of which are hand tokens and some are cube tokens. 
2) Concat a special `CLS_token` to the 0th index. This token is always the one scored against.
2) Run sequential transformers (attn -> MLP)
4) Output `H: (n, d)`
5) Grab the CLS token, `q = H[0]`
6) Generate `C` : Pass every valid action (as determined by the environment) in a small MLP, stack into matrix `C` 
7) Compute `res = softmax(C * q)`. This scores each action against the models predicted action in the CLS token, then softmax to choose the highest match
8) Sample random action from res distribution

Explanation on quirks:
- Hand data must be represented from gamepieceid, since each hand is a collection of cubes.
- I did some empirical testing in Unity on a large ish map and discovered the amount of all possible actions is 5-10k, which is completely reasonable and computable for a set point transformer

## Training
- Parallelize in batches on my m4 max macbook

## Possible future work
- Turn score_layer into transformer that attends only to place cubes, instead of just a multiplayer MLP
- Put all action as tokens that can be updated, not just gamepieces in hand, to reduce the logic the model has to learn
- Brute force tree search approach: 20k action possibilities per move, but actions later in the tree are heavily repeated and so can
be cached.
- Give the priviledged model raw probailities from the game actions, let it do a brute force search better