from Network import transformer
import torch

if __name__ == "__main__":
    model = transformer.SetPointTransformer(128, 1)
    dummy_X_place = torch.ones(100, 18) # 100 placed cubes
    dummy_X_hand = torch.ones(50, 1) # 50 cards in hand
    dummy_y_actions = torch.ones(10000, 5)
    print(model.forward(dummy_X_place, dummy_X_hand, dummy_y_actions)[0])