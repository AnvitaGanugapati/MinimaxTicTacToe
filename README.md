# MinimaxTicTacToe
TicTacToe game, optimized with the MiniMax AI Algorithm

# Overview
This is a simple command-line implementation of the classic Tic-Tac-Toe game with an AI player using the minimax algorithm. The game allows you to play against the AI, and the AI makes optimal moves to maximize its chances of winning or forcing a tie.

# How to Play
The game board is a 3x3 grid, where each cell is represented by its coordinates (0-based index). The rows and columns are numbered from 0 to 2.

When prompted, enter the coordinates (x and y) of your move. For example, if you want to place your marker in the middle cell, enter 1 for both x and y (0-based index).

The AI player ("X") will make the very first move, and then automatically make its move after you make a valid move.

Continue playing moves until one of the players wins or the game ends in a tie.

# Minimax Algorithm
The AI player's moves are determined using the minimax algorithm. The algorithm exhaustively searches through all possible moves and simulates the game outcome for each move. It assigns scores based on the result of the game (win, loss, or tie) and selects the move with the highest score for the AI player ("X"). My explanations of the logic are commented throughout.

# My Diagram
Below I've made a diagram of the algorithm, depicting 1 of 4 possible initial moves from the current game state.
![Minimax Demo](https://github.com/AnvitaGanugapati/MinimaxTicTacToe/assets/123125052/32e749ad-5ac1-4932-a494-aca0c36f1ab8)


# Acknowledgments
This implementation is based on the "[Programming Projects for Advanced Beginners](https://robertheaton.com/2018/10/09/programming-projects-for-advanced-beginners-3-b/)" website and a [YouTube tutorial](https://www.youtube.com/watch?v=trKjYdBASyQ&ab_channel=TheCodingTrain) by The Coding Train. The minimax algorithm and AI logic were adapted from those resources.

