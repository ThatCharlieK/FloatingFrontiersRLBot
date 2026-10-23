# ABOUT
Floating Frontiers RL bot is trained to play [Floating Frontiers](https://store.steampowered.com/app/4034080/Floating_Frontiers/), A city building strategy game I developed.
- Trained in a fast C RL enviornment 1:1 replica of the real game logic
- Set point transformer achitecture, generates score all valid actions and picks highest one
- [TODO]M parameter network trained locally on M4 Macbook pro

# The RL enviornment
`/Engine` is a fast replica of floating frontiers logic, written in C. The real game has four maps, but for now the bot only plays the first map, which has simpler rules.




# Set pointer transformer
The bot is a set pointer transformer. The game state is represented as two data types:
1) Cubes on the board are unordered tokens, inputed as `[cube_id, x, y, z]`
2) Gamepieces in hand are unordered tokens, inputed as `[gamepieceID, x, y, z, rot]`
The model outputs a single `[GamepieceID, x, y, z, rot]` action

The flow is:
1) Input the `X: (n, 4)` input to the network
2) Run sequential transformers (attn -> MLP)
3) Cross attention inject a learned embedding of each gamepiece in hand in some layers
4) Output `H: (n, d)`
5) Grab last element, `q = H[-1]`
6) Generate `C` : Pass every valid action (as determined by the environment) in a learned embedding matrix, stack into matrix `C` 
7) Computer `res = softmax(C * q)`. This does a dot product w/ every action against the model's output `q` , then softmax.
8) Sample random action from res distribution

Explanation on quirks:
- Hand data must be represented from gamepieceid, since each hand is a collection of cubes.
- I did some empirical testing in Unity on a large ish map and discovered the amount of all possible actions is 5-10k, which is completely reasonable and computable for a set point transformer

## Training
- Parallelize in batches on my m4 max macbook
