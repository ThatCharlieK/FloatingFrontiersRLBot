import torch
from jaxtyping import Float
import torch.nn as nn
import math

class MultiHeadAttentionMLPBlock(nn.Module):
    """
    Does a single pass multi-headed attention, then an MLP
    """

    def __init__(self, block_dim: int, MLP_depth: int = 2, n_heads: int = 4):
        super().__init__()
        self.block_dim = block_dim
        self.n_heads = n_heads

        # n_heads parallel heads of attention, each W_q,k,v is (block_dim -> block_dim/n_heads),
        # stacked into one big mat
        self.W_q = nn.Linear(block_dim, block_dim)
        self.W_k = nn.Linear(block_dim, block_dim)
        self.W_v = nn.Linear(block_dim, block_dim)

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
        # so each Q, K is (n_heads, n, block_dim / n_heads)
        Q = Q.reshape(self.n_heads, Q.size(0), self.block_dim // self.n_heads)
        K = K.reshape(self.n_heads, K.size(0), self.block_dim // self.n_heads)
        V = V.reshape(self.n_heads, V.size(0), self.block_dim // self.n_heads)

        # attention then treats the outer dim as a batch
        S = Q @ K.transpose(-2, -1) / math.sqrt(self.block_dim // self.n_heads)
        # here A = (n_heads, n, n)
        A = torch.softmax(S, dim=-1)
        # res = (n_heads, n, block_dim / n_heads)
        res = A @ V

        # reshape heads back together
        res = res.reshape(X.size(0), self.n_heads, self.block_dim / self.n_heads)
        res = res.reshape(X.size(0), self.block_dim)
        
        # Concat back together

        # MLP on each token

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