# ConnectFour: A C Implementation of the Classic Game

## Connect 4 Game Project for ENGG1110

## Project Overview
This project implements the game of Connect 4 in C for the ENGG1110 Problem Solving by Programming course at The Chinese University of Hong Kong. The game supports both one-player (against a computer) and two-player modes.

## Features
- Interactive game board (7 columns x 6 rows)
- Support for 1 or 2 human players
- Computer player with strategic move selection
- Win detection (horizontal, vertical, and diagonal)
- Draw game detection

## How to Play
1. Run the program
2. Enter the number of human players (1 or 2)
3. Take turns to choose a column (1-7) to drop your mark
4. The first player to connect four marks in a row (horizontally, vertically, or diagonally) wins
5. If the board fills up with no winner, it's a draw

## Computer Player Strategy
The computer player uses the following strategy to select its moves:
1. Look for a winning move
2. If no winning move, look to block the human player's winning move
3. If no blocking move needed, choose the column with the fewest marks

## Project Structure
- `initGameBoard()`: Initializes the game board
- `printGameBoard()`: Displays the current game state
- `placeMarkByHumanPlayer()`: Handles human player moves
- `placeMarkByComputerPlayer()`: Implements computer player strategy
- `hasWinner()`: Checks if there's a winner
- `isFull()`: Checks if the board is full (draw game)

## Compilation and Execution
Compile the program using a C compiler, for example:

## Notes
- The program uses only the `stdio.h` header
- No global variables are used
- The code follows the specific output format required by the project description

## Author
Jatin Gupta
Student ID: 1155172419
Class/Section: ENGG1110A
Date: 18/11/2021

## Academic Honesty
This project was completed in compliance with the University's academic honesty policy. The full declaration can be found at the beginning of the source code.