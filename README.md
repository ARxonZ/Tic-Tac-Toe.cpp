# Tic-Tac-Toe Game (C++)

A console-based, two-player Tic-Tac-Toe game written in C++. Players take turns marking a 3×3 grid, and the program detects wins and ties automatically.

## Features

- 2-player game (Player 1 = `X`, Player 2 = `O`)
- 3×3 grid board with numbered positions (1-9)
- Win detection (rows, columns, diagonals)
- Tie detection
- Input validation (invalid numbers, out-of-range, already-taken cells)
- Scoreboard tracking Player 1 wins, Player 2 wins, and ties
- Play-again option

## How to Play

1. Player 1 uses `X`, Player 2 uses `O`.
2. On your turn, enter a position number (1-9) to place your symbol.
3. The first player to get three symbols in a row (horizontal, vertical, or diagonal) wins.
4. If all 9 cells are filled with no winner, the game is a tie.

```
      1 | 2 | 3
     ---+---+---
      4 | 5 | 6
     ---+---+---
      7 | 8 | 9
```

## Getting Started

### Prerequisites

- A C++ compiler such as `g++` (C++11 or later)

### Compile

```bash
g++ main.cpp -o tictactoe
```

### Run

```bash
./tictactoe        # Linux / macOS
tictactoe.exe      # Windows
```

## Sample Output

```
=====================================
       TIC-TAC-TOE (2 PLAYERS)
=====================================

      1 | 2 | 3
     ---+---+---
      4 | 5 | 6
     ---+---+---
      7 | 8 | 9

Player 1 (X) - enter position (1-9): 5
...
*** Player 1 (X) wins! ***
---------- SCOREBOARD ----------
Player 1 (X): 1
Player 2 (O): 0
Ties        : 0
--------------------------------
Play again? (y/n):
```

## Project Structure

```
tic-tac-toe/
├── main.cpp    # Game source code
└── README.md   # Project documentation
```

## Concepts Used

- Classes and objects (OOP)
- 2D arrays
- Loops and conditionals
- Input validation with `cin`
- Functions and code modularity

## Author

Your Name

## License

This project is open source and available for educational use.

