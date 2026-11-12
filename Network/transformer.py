import torch
from jaxtyping import Float
import torch.nn as nn
import math
from Engine.ffengine import NUM_GAMEPIECES


class MultiHeadAttentionMLPBlock(nn.Module):
    """
    Does a single pass multi-headed attention, then an MLP
    """

    def __init__(self, block_dim: int, n_heads: int = 4, cross_attend_q = False):
        super().__init__()
        self.block_dim = block_dim
        self.n_heads = n_heads
        self.cross_attend_q = cross_attend_q
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

    def forward(self, X: torch.Tensor, X2: torch.Tensor | None = None, X_mask: torch.Tensor | None = None):
        """
        Pass X through a forward pass of attention to MLP.
        If cross_attend_q, then Q comes from X, and K,V comes from X2
        
        :param X: (b, n, block_dim) matrix of tokens that undergo self attention
        :type X: torch.Tensor

        :param X2: (b, n, block_dim) Optional matrix for cross attention. If provided,
        K, V comes from X2 rather than X
        :type X: torch.Tensor

        :param X_mask: (b, n_k), bool with true := real token. An optional mask for X. 
        Values that are false in the mask are set to -inf for softmax
        :type X: torch.Tensor
        
                
        """
        # Apply each head of attention
        Q = self.W_q(X)
        if self.cross_attend_q:
            K = self.W_k(X2)
            V = self.W_v(X2)
        else:
            K = self.W_k(X)
            V = self.W_v(X)

        # reshape into separate heads,
        # so each Q, K, Vis (b, n_heads, n or n_k, block_dim / n_heads)
        batch_size = Q.size(0)
        Q = Q.reshape(batch_size, Q.size(1), self.n_heads, self.block_dim // self.n_heads).transpose(1, 2) # Q = (b, n_heads, n, head_out)
        K = K.reshape(batch_size, K.size(1), self.n_heads, self.block_dim // self.n_heads).transpose(1, 2) # K = (b, n_heads, n_k, head_out)
        V = V.reshape(batch_size, V.size(1), self.n_heads, self.block_dim // self.n_heads).transpose(1, 2) # V = (b, n_heads, n_k, head_out)

        """
        Transposing K gives (b, n_heads, head_out, n_k)
        Then Q @ K.T(-2, -1) gives (b, n_heads, n, head_out) @ (b, n_heads, head_out, n_k) = (b, n_heads, n, n_k)
        since the outer dimensions are treated as the batch.

        So its doing softmax(Q@K.T / sqrt(d_k)) @ V, over n_heads,
        just using a batch dimension in front
        """
        S = Q @ K.transpose(-2, -1) / math.sqrt(self.block_dim // self.n_heads)
        if X_mask is not None:
            # apply the mask: Because of batching, set garbage values that the C engine isn't using for this game
            # to -inf for the softmax, throwing them away.
            # X_mask[:, None, None, :] broadcasts X_mask from (b, n_k) into (b, 1, 1, n_k) so it matches dims
            S = S.masked_fill(~X_mask[:, None, None, :], float("-inf"))
        A = torch.softmax(S, dim=-1)
        # res = (b, n_heads, n, n_k) @ (b, n_heads, n_k, head_out) = (b, n_heads, n, head_out)
        res = A @ V

        # Concat parallel heads back together

        # tranpose from (b, n_heads, n, head_out) to (b, n, n_heads, head_out)
        res = res.transpose(1, 2)
        # reshape to (b, n, block_dim)
        res = res.reshape(X.size(0), X.size(1), self.block_dim)

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

    def __init__(self, block_dim: int = 128, num_blocks = 10, num_score_blocks = 2):
        super().__init__()
        self.block_dim = block_dim
        self.placed_input_layer = nn.Linear(18, block_dim) # project up hand -> transformer size
        self.blocks = nn.ModuleList([MultiHeadAttentionMLPBlock(block_dim) for _ in range(num_blocks)])

        self.score_blocks = nn.ModuleList([MultiHeadAttentionMLPBlock(block_dim, cross_attend_q=True) for _ in range(num_score_blocks)])
        self.score_layer = nn.Linear(self.block_dim + 5, block_dim) # gp_id embedding + [x, y, z, rot, points]
        
        """
        Classification token:
        instead of scoring against the last block (which is random dependent on ordering)
        we score against the same dedicated learned CLS_token at the 0 position
        """
        self.CLS_token = nn.Parameter(torch.normal(mean=0, std=0.05, size = (1, 1, block_dim)))

        """
        Value head to improve learning signal
        Learns to predict, from this state (by parsing a pooled vector of all tokens)
        how many more points to expect until the game ends
        """
        self.value_head = nn.Sequential(
                    nn.Linear(block_dim * 2, block_dim),
                    nn.ReLU(),
                    nn.Linear(block_dim, 1)
                )


        # encode a single number id into a high dimensional vector
        # allowing the model to differentiate between piece 37, and 36, easily, for ex
        # essentially one hot encoding -> matmul
        self.gp_id_embedder = nn.Embedding(NUM_GAMEPIECES, block_dim)

        # global features (ie score) are injected into a special global_features_token,
        # in the second slot next to the cls token. This way the model can learn with
        # global game state information during atttention
        self.global_features_layer = nn.Sequential(
                    nn.Linear(3, block_dim),
                    nn.ReLU(),
                    nn.Linear(block_dim, block_dim)
                )

    def forward(self, X_placed: torch.Tensor, X_placed_mask: torch.Tensor,
                X_hand: torch.Tensor, X_hand_mask: torch.Tensor,
                y_actions: torch.Tensor, y_actions_mask: torch.Tensor,
                global_features: torch.Tensor
                ) -> tuple[torch.Tensor, torch.Tensor]:
        """
        
        :param X_placed: Placed game cubes. Each cube on board is [x, y, z, bit1, bit2, bit3...],
        where the bits come from the 16 bit bit packed representation, minus the fill bit
        :type X: Float[Tensor, "b, n 18"]

        :param X_placed_mask: Each batch has a different number of placed cubes,
        so X_placed_mask is bool with true for real token, false for garbage

        :param X_hand: Gamepiece Ids in the hand
        :type X: Float[Tensor, "b, n 1"]

        :param X_hand_mask: Each batch has a different number of hands,
        so X_placed_mask is bool with true for real token, false for garbage

        :param y_actions: Available actions to the player, enumerated through all placement positions.
        Each action is parameterized by a gamepiece ID, a rotation, and a world position,
        plus the points playing it would score right now (pre-scaled, see train.py),
        so its (gamepiece_id, x, y, z, rot, points)
        :type y_actions: Float[Tensor, "b, n, 6"]

        :param y_actions_mask: Each batch has a different number of actions,
                        we must pad to -inf so that we don't use the junk values.

        :param global_features: Global features about the game, projected into a single token.
        (b, 3), each row is [score, points until next level, level index], pre-scaled to small numbers (see train.py)
                        
        
        :return: Two tensors:
        (b, m) tensor of LOG probabilities across all valid actions to take. .exp() gives the probabilities
        (b,) tensor of predicted remaining scores at each game (in units of train.VALUE_SCALE points), predicted by the value head
        :rtype: tensors
        """

        # project placed (n, 18) and (n, 1) to same dimensions
        n_batch = X_placed.size(0)

        h_placed = self.placed_input_layer(X_placed)
        h_hand = self.gp_id_embedder(X_hand[..., 0].long())
        cls = self.CLS_token.expand(n_batch, -1, -1) # copy cls along batch dim
        global_feat = self.global_features_layer(global_features).unsqueeze(1) # (b, 3) -> (b, 1, d)
        h = torch.cat((cls, global_feat, h_placed, h_hand), dim = 1)

        cls_mask = torch.ones(n_batch, 2, dtype=torch.bool, device=X_placed_mask.device) # CLS and the global features token are always real
        h_mask = torch.cat((cls_mask, X_placed_mask, X_hand_mask), dim=1)

        # pass through attention-MLP blocks
        for block in self.blocks:
            h = block(h, X_mask=h_mask)

        # h is now (b, n+2, d)
        # pull out the CLS token and use it to compare
        q = h[:, 0] # (b, d)

        # y_actions is [gp_id, x, y, z, rot, points], and we embed it to
        # [gp_id_embedding] + [x, y, z, rot, points], before then embedding into another MLP
        # this lets gp_id, a raw number, be more understandable
        y_gp_id_embedding = self.gp_id_embedder(y_actions[..., 0].long())
        y_embedded = torch.cat((y_gp_id_embedding, y_actions[..., 1:]), dim = -1)
        y_h = self.score_layer(y_embedded)
        
        # run y_embedded through a transformer, Q's coming from actions, KV coming from h
        # this allows the model to learn more when creating its action embedding
        # full self attention here is too expensive since theres 20k+ actions

        for score_block in self.score_blocks:
            y_h = score_block(y_h, h, X_mask=h_mask)        

        # run the value head; It needs to predict the remaining score,
        # so it needs all information that includes both cubes, hands, and actions,
        # so run it on a pooled y_h
        masked_y_h = y_h.masked_fill(~y_actions_mask[:, :, None], 0) # zero out garbage values
        # average across the real tokens only, going (b, m, d) -> (b, d)
        averaged = masked_y_h.sum(dim = 1) / y_actions_mask.sum(dim = 1, keepdim = True)
        pooled = torch.cat((q, averaged), dim = -1)
        preds = self.value_head(pooled).squeeze(-1) # (b, 1) -> (b,)

        # squeezes so (b, m, d) @ (b, d) becomes (b, m, d) @ (b, d, 1)
        # / sqrt(d) like attention: y_h and q are layer-normed, so the raw dot product is ~±d and one
        # optimizer step could swing the policy wildly (runs collapsed to scoring 0 from scratch)
        logits = (y_h @ q.unsqueeze(2)).squeeze(2) / math.sqrt(self.block_dim) # logits = (b, m)

        # apply the mask: Discard garbage actions, setting them to -inf for softmax
        logits = logits.masked_fill(~y_actions_mask, float("-inf"))

        # res is vector of log probabilities over all y actions.
        # log_softmax instead of log(softmax): a tiny probability can round to 0 in softmax,
        # and log(0) = -inf -> NaN gradients. log_softmax computes the log directly, so it never hits 0
        res = logits.log_softmax(dim=-1)
        return (res, preds)