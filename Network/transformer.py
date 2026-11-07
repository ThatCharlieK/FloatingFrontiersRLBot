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

class Transformer(nn.Module):

    def __init__(self, block_dim: int = 128, num_blocks = 10):
        super().__init__()
        self.block_dim = block_dim
        self.input_layer = nn.Linear(4, block_dim)
        self.blocks = nn.ModuleList([MultiHeadAttentionMLPBlock(block_dim) for _ in range(num_blocks)])
        self.score_layer = nn.Linear(4, block_dim) # [id, x, y, z] -> [128]

    def forward(self, x: torch.Tensor, y: torch.Tensor) -> torch.Tensor:
        """
        Docstring for forward
        
        :param x: Placed game cubes
        :type x: Float[Tensor, "n 4"]
        :param y: Tensor of valid actions (gamepiece_id, x, y, z)
        :type y: Float[Tensor, "n, 4"]

        :return: (1,) tensor of idx in y of valid action to take
        :rtype: tensors
        """

        # project input to block dims
        h = self.input_layer(x)

        # pass through attention-MLP blocks
        for block in self.blocks:
            # TODO inject cross attention from hand into here
            h = block(h)

        # h is now (n, d)
        # pull our last token
        q = h[-1]

        # each row of C is similarity with q action
        C = self.score_layer(y)

        # res is vector of probaility distributions over all y actions
        res = (C @ q).softmax(dim=0)

        # pick random action based on res distribution 
        # pick random based on similiarty with res
        idx = torch.multinomial(res, 1)
        return idx