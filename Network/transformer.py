import torch
from jaxtyping import Float
import torch.nn as nn
import math

class MultiHeadAttentionMLPBlock(nn.Module):
    """
    Does a single pass multi-headed attention, then an MLP
    """

    def __init__(self, block_dim: int, n_heads: int = 4):
        super().__init__()
        self.block_dim = block_dim
        self.n_heads = n_heads

        """
        n_heads parallel heads of attention, each with their own W_q,k,v as (block_dim, block_dim/n_heads),
        ie the head_out is defined to be block_dim/n_heads,
        stacked into one big mat
        """
        self.W_q = nn.Linear(block_dim, block_dim)
        self.W_k = nn.Linear(block_dim, block_dim)
        self.W_v = nn.Linear(block_dim, block_dim)

        # output projection
        self.W_o = nn.Linear(block_dim, block_dim)

        # learned normalization, output = y * normalized + b
        self.layer_norm_1 = nn.LayerNorm(block_dim)
        self.layer_norm_2 = nn.LayerNorm(block_dim)

        self.MLP = nn.Sequential(
            nn.Linear(block_dim, block_dim * 4),
            nn.ReLU(),
            nn.Linear(block_dim * 4, block_dim)
        )

    def forward(self, X: torch.Tensor):
        """
        Docstring for forward
        
        :param X: (n, block_dim) matrix of each of the n tokens per placed gamecube
        :type X: torch.Tensor
        """
        # Apply each head of attention
        Q = self.W_q(X)
        K = self.W_k(X)
        V = self.W_v(X)

        # reshape into separate heads,
        # so each Q, K, Vis (n_heads, n, block_dim / n_heads)
        Q = Q.reshape(Q.size(0), self.n_heads, self.block_dim // self.n_heads).transpose(0, 1) # Q = (n_heads, n, head_out)
        K = K.reshape(K.size(0), self.n_heads, self.block_dim // self.n_heads).transpose(0, 1) # K = (n_heads, n, head_out)
        V = V.reshape(V.size(0), self.n_heads, self.block_dim // self.n_heads).transpose(0, 1) # V = (n_heads, n, head_out)

        """
        Transposing K gives (n_heads, head_out, n)
        Then Q @ K.T(-2, -1) gives (n_heads, n, head_out) @ (n_heads, head_out, n) = (n_heads, n, n)
        since the outer dimension is treated as the batch.

        So its doing softmax(Q@K.T / sqrt(d_k)) @ V, over n_heads,
        just using a batch dimension in front
        """
        S = Q @ K.transpose(-2, -1) / math.sqrt(self.block_dim // self.n_heads)
        A = torch.softmax(S, dim=-1)
        # res = (n_heads, n, n) @ (n_heads, n, head_out) = (n_heads, n, head_out)
        res = A @ V

        # Concat parallel heads back together

        # tranpose from (n_heads, n, head_out) to (n, n_heads, head_out)
        res = res.transpose(0, 1)
        # reshape to (n, block_dim)
        res = res.reshape(X.size(0), self.block_dim)

        """
        apply output project matrix to mix
        At this point each row of res is really 
        [---tokenNfromhead1---- |---tokenNfromhead2---|---tokenNfromhead3----|....]
        So a simple mat mul can mix info from each head
        """
        res = self.W_o(res)
        # add to residual
        X = X + res
        # per-token normalization
        X = self.layer_norm_1(X)

        # MLP on each token
        X = X + self.MLP(X)
        X = self.layer_norm_2(X)
        return X

class SetPointTransformer(nn.Module):

    def __init__(self, block_dim: int = 128, num_blocks = 10):
        super().__init__()
        self.block_dim = block_dim
        self.placed_input_layer = nn.Linear(18, block_dim) # project up hand -> transformer size
        self.hand_input_layer = nn.Linear(1, block_dim) # project from ID -> transformer size
        self.blocks = nn.ModuleList([MultiHeadAttentionMLPBlock(block_dim) for _ in range(num_blocks)])
        
        self.score_layer = nn.Sequential(
            nn.Linear(5, block_dim * 4),
            nn.ReLU(),
            nn.Linear(block_dim * 4, block_dim * 4),
            nn.ReLU(),
            nn.Linear(block_dim * 4, block_dim),
        )
        
        """
        Classification token:
        instead of scoring against the last block (which is random dependent on ordering)
        we score against the same dedicated learned CLS_token at the 0 position
        """
        self.CLS_token = nn.Parameter(torch.normal(mean=0, std=0.05, size = (1, block_dim)))

    def forward(self, X_placed: torch.Tensor, X_hand: torch.Tensor, y_actions: torch.Tensor) -> torch.Tensor:
        """
        Docstring for forward
        
        :param X_placed: Placed game cubes. Each cube on board is [x, y, z, bit1, bit2, bit3...],
        where the bits come from the 16 bit bit packed representation, minus the fill bit
        :type X: Float[Tensor, "n 18"]

        :param X_hand: Gamepiece Ids in the hand
        :type X: Float[Tensor, "n 1"]


        :param y_actions: Available actions to the player, enumerated through all placement positions.
        Each action is parameterized by a gamepiece ID, a rotation, and a world position,
        so its (gamepiece_id, x, y, z, rot)
        :type y_actions: Float[Tensor, "n, 5"]

        :return: (1,) tensor of idx in y of valid action to take
        :rtype: tensors
        """

        # project placed (n, 18) and (n, 1) to same dimensions
        h_placed = self.placed_input_layer(X_placed)
        h_hand = self.hand_input_layer(X_hand)
        h = torch.cat((self.CLS_token, h_placed, h_hand), dim = 0)

        # pass through attention-MLP blocks
        for block in self.blocks:
            h = block(h)

        # h is now (n+1, d)
        # pull out the CLS token and use it to compare
        q = h[0]

        # each row of C is similarity with q action
        C = self.score_layer(y_actions)

        # res is vector of probaility distributions over all y actions
        res = (C @ q).softmax(dim=0)

        # pick random action based on res distribution 
        # pick random based on similiarty with res
        idx = torch.multinomial(res, 1)
        return idx
    
    