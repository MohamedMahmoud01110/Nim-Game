# Nim Game in C++

## Description

This repository contains a C++ implementation of the Nim Game, a mathematical strategy game where two players take turns removing coins from piles. The game offers two variants:

- **Variant 1:** Players take coins from a single pile. The game starts with 23 coins, and players can take between 1 to 3 coins on their turn. The player forced to take the last coin loses.
  
- **Variant 2:** Players pick coins from one of three boxes containing 3, 4, and 5 coins respectively. Each player picks from a box that their opponent did not choose. The objective is to reduce the opponent’s pile of coins to zero first.

## Features

- **User Input:** Players choose who goes first in Variant 1. In Variant 2, each player selects which box to pick from.
- **Computer AI:** In Variant 1, the computer uses an algorithm to make strategic moves.
- **Winning Strategy:** In both variants, the aim is to force your opponent into a losing position.

## How to Play

### Variant 1:
1. The game begins with 23 coins.
2. Players (human and computer) take turns picking between 1 to 3 coins from the pile.
3. The game ends when no coins remain, and the winner is the one who has collected an even number of coins.

### Variant 2:
1. The game starts with three boxes, containing 3, 4, and 5 coins, respectively.
2. Players pick from different boxes, removing between 1 to 3 coins per turn.
3. The player who reduces the opponent’s pile to zero wins.

## How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/nim-game.git
    ```
2. Compile the code using a C++ compiler (e.g., g++):
    ```bash
    g++ nim_game.cpp -o nim_game
    ```
3. Run the executable:
    ```bash
    ./nim_game
    ```

## Contributions

Feel free to fork this project, open issues, and make pull requests to enhance the game or fix bugs!

## License

This project is licensed under the MIT License.
