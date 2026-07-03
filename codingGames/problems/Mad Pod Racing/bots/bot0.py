from dataclasses import dataclass
import sys
from typing import List, Tuple

ME, FOE = 0, 1
DEBUG = True

@dataclass
class Pos:
    x: int
    y: int
    
    @staticmethod
    def distance(pos0: "Pos", pos1: "Pos") -> int:
        return abs(pos0.x - pos1.x) + abs(pos0.y - pos1.y)
    
class Board: 
    def __init__(self):
       self.epoch: int = 0
       self.lap: int = 0
       self.checkpoints_pos: list[Pos] = []
        
    def update_checkpoint_pos(self, checkpoint_pos: Pos) -> None: 
        if len(self.checkpoints_pos) and checkpoint_pos == self.checkpoints_pos[0]:   
            self.lap += 1
        elif self.lap == 0:
            self.checkpoints_pos.append(checkpoint_pos)
            
    def get_next_checkpoint_pos(self, next_checkpoint_idx: int) -> Pos:
        return self.checkpoints_pos[next_checkpoint_idx]
    
class State:
    def __init__(self,
                curretn_pos: Tuple[Pos, Pos],
                next_chekpoint_angle: int,
                next_checkpoint_dist: int,
                next_checkpoint_idx: int,
                last_pos: Pos | None):
        
        self.current_pos: Tuple[Pos, Pos] = curretn_pos
        self.last_pos: Pos | None = last_pos

        self.next_checkpoint_angle: int = next_chekpoint_angle
        self.next_checkpoint_idx: int = next_checkpoint_idx
        self.next_checkpoint_dist: int = next_checkpoint_dist
        
    def get_speed(self) -> int: 
        if self.last_pos is None: 
            return 0
        else:
            return Pos.distance(self.current_pos[ME], self.last_pos)

    def generate_next_move(self, board: Board) -> tuple[Pos, int, bool]:
        boost = board.epoch == 0
        
        
        if self.get_speed() < 150: 
            thrust = 100
        elif self.next_checkpoint_angle > 90 or self.next_checkpoint_angle < -90:
            thrust = 0
        else: 
            thrust = 100

        return board.get_next_checkpoint_pos(self.next_checkpoint_idx), thrust, boost
        
class Game:
    def __init__(self): 
        self.board = Board()
        self.state = State((Pos(0, 0), Pos(0, 0)), 0, 0, -1, None)
        
    def get_input_and_update_state(self) -> None: 
        x, y, next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle = [int(i) for i in input().split()]
        opponent_x, opponent_y = [int(i) for i in input().split()]
        
        if DEBUG:
            print(f"Current x: {x} y: {y}", file=sys.stderr)
            print(f"Next checkpoint x: {next_checkpoint_x} y: {next_checkpoint_y}", file=sys.stderr)
            print(f"Next checkpoint dist: {next_checkpoint_dist} angle: {next_checkpoint_angle}", file=sys.stderr)
            print(f"Opponent x: {opponent_x} y: {opponent_y}", file=sys.stderr)
        
        self.board.update_checkpoint_pos(Pos(next_checkpoint_x, next_checkpoint_y))

        pos: Pos = Pos(x, y)
        opponent_pos = Pos(opponent_x, opponent_y)
        
        next_checkpoint_idx = (self.state.next_checkpoint_idx + 1) % len(self.board.checkpoints_pos) if self.state.next_checkpoint_idx != -1 else 0
        game.state = State((pos, opponent_pos), next_checkpoint_angle, next_checkpoint_dist, next_checkpoint_idx, game.state.current_pos[ME])
    
    def generate_next_move(self) -> tuple[Pos, int, bool]:
        return self.state.generate_next_move(self.board)
    
    def print_output(self, next_move: Pos, thrust: int, boost: bool) -> None:
        self.board.epoch += 1 
        
        print(str(next_move.x) + " " + str(next_move.y) + " ", end="")
        if boost: 
            print("BOOST")
        else:
            print(str(thrust))

if __name__ == "__main__":
    game = Game()

    while True:
        game.get_input_and_update_state()
        
        next_move, thrust, boost = game.generate_next_move()
        game.print_output(next_move, thrust, boost)


