"""
Checkpointing and logging for training runs.

Each run gets its own folder, runs/<start time>/:
    best.pt          the model with the best average score so far (overwritten on every new best)
    milestones/      a kept copy each time the best score rises 10% past the last milestone
    log.csv          one row per update step: step, average score, best, seconds per step, memory
    scores.png       the score plot, redrawn every step

A checkpoint file is a dict: {"state_dict", "config", "step", "score"}.
config holds the SetPointTransformer constructor args, so load_model() can rebuild it.
"""

import csv
import resource
import time
from datetime import datetime
from pathlib import Path

import matplotlib.pyplot as plt
import torch

from Network import transformer

RUNS_DIR = Path(__file__).resolve().parent / "runs"
MILESTONE_GAIN = 1.10  # keep a milestone when the best score beats the last milestone by 10%


def model_config(model: transformer.SetPointTransformer) -> dict:
    return {
        "block_dim": model.block_dim,
        "num_blocks": len(model.blocks),
        "num_score_blocks": len(model.score_blocks),
    }


def load_model(path) -> tuple[transformer.SetPointTransformer, dict]:
    """Rebuild a model from a checkpoint file. Returns (model in eval mode, the checkpoint dict)."""
    ckpt = torch.load(path, map_location="cpu", weights_only=False)
    model = transformer.SetPointTransformer(**ckpt["config"])
    model.load_state_dict(ckpt["state_dict"])
    model.eval()
    return model, ckpt


class TrainingTracker:
    def __init__(self, run_name: str | None = None):
        self.dir = RUNS_DIR / (run_name or datetime.now().strftime("%Y-%m-%d_%H-%M-%S"))
        (self.dir / "milestones").mkdir(parents=True, exist_ok=True)
        self.best = float("-inf")
        self.last_milestone = None
        self.scores = []
        self.last_time = time.time()

        self.log_path = self.dir / "log.csv"
        with open(self.log_path, "w", newline="") as f:
            csv.writer(f).writerow(["step", "avg_score", "best", "sec_per_step", "max_rss_mb", "time"])

        self.fig, self.ax = plt.subplots()
        print(f"[checkpoint] run folder: {self.dir}")

    def _save(self, path: Path, model, step: int, score: float):
        torch.save({"state_dict": model.state_dict(), "config": model_config(model),
                    "step": step, "score": score}, path)

    def update(self, step: int, avg_score: float, model):
        """Call once per update step, after the optimizer step."""
        now = time.time()
        sec = now - self.last_time
        self.last_time = now
        self.scores.append(avg_score)

        if avg_score > self.best:
            self.best = avg_score
            self._save(self.dir / "best.pt", model, step, avg_score)
            if self.last_milestone is None or avg_score >= self.last_milestone * MILESTONE_GAIN:
                self.last_milestone = avg_score
                self._save(self.dir / "milestones" / f"step{step:05d}_score{avg_score:.1f}.pt", model, step, avg_score)
                print(f"[checkpoint] milestone: step {step}, score {avg_score:.1f}")

        rss_mb = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / 2**20  # bytes on macOS
        with open(self.log_path, "a", newline="") as f:
            csv.writer(f).writerow([step, f"{avg_score:.2f}", f"{self.best:.2f}", f"{sec:.1f}",
                                    f"{rss_mb:.0f}", datetime.now().strftime("%H:%M:%S")])

        self.ax.clear()
        self.ax.plot(self.scores)
        self.ax.set_xlabel("update step")
        self.ax.set_ylabel("average final score")
        self.ax.set_title(f"best {self.best:.1f}")
        self.fig.savefig(self.dir / "scores.png", dpi=100)
