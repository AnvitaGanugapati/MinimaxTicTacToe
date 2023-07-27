#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <random>
#include <map>
using namespace std;


vector<vector<string> > clean_board() {
    std::vector< std::vector <string> > board;
    for(int i=0; i<3; i++) {
        std::vector <string> inner;
        for(int j=0; j<3; j++) {
            inner.push_back("  ");    
        }
    board.push_back(inner);
    }
    return board;
}

// Grabs coordinates from user
vector<int> get_move() {
    vector<int> coordinates;
    int x; 
    int y;
    cout << "What is the x coordinate of your move? ";
    cin >> x;
    cout << "What is the y coordinate of your move? ";
    cin >> y;
    coordinates.push_back(x);
    coordinates.push_back(y);
    cout << "(";
    for (int i = 0; i < coordinates.size(); i++) {
        cout << coordinates[i];
        if (i != coordinates.size() - 1) {
            cout << ",";
        }  
    }
    cout << ")" << endl;
    return coordinates;
   
}


bool is_valid_move(vector<vector<string> > board, vector<int> coords) {
    if (coords[0] > 2 || coords[0] < 0 || coords[1] > 2 || coords[1] < 0) {
        // Invalid move entered
        cout << "Out of bounds. Try again" << endl;
        return false;
    }

    if (board[coords[0]][coords[1]] != "  ") {
        // Invalid move entered
        cout << "There is already a marker here. Try again" << endl;
        return false;
    }
    return true;
}

 // Takes in coordinates and places marker 
vector<vector<string> > make_move(vector<vector<string> > board, vector<int> coords, string player) {
    board[coords[0]][coords[1]] = player;
    return board;
}

// Draws TTT board
void render (vector<vector<string> > board) {
    cout << "    0 " << " 1 " << " 2 " << endl;
    cout << "   _____________" << endl;
    for (int i = 0; i < board.size(); i++) {
        cout << i << "| ";
        for (int j = 0; j < board.at(i).size(); j++) {
            cout << board[j][i];
        }
        cout << endl;
    }
    
}

string getWinner(std::vector<std::vector<std::string> > winning_board) {
    // Check rows for a win
    string winner;
    for (int i = 0; i < 3; ++i) {
        if (winning_board[i][0] == winning_board[i][1] && winning_board[i][1] == winning_board[i][2] && winning_board[i][0] != "  ") {
            winner = winning_board[i][0];
            return winner;
            cout << " WON THE GAME";
        }
    }

    // Check columns for a win
    for (int j = 0; j < 3; ++j) {
        if (winning_board[0][j] == winning_board[1][j] && winning_board[1][j] == winning_board[2][j] && winning_board[0][j] != "  ") {
            winner = winning_board[0][j];
            return winner;
            cout << " WON THE GAME";
        }
    }

    // Check diagonals for a win
    if (winning_board[0][0] == winning_board[1][1] && winning_board[1][1] == winning_board[2][2] && winning_board[0][0] != "  ") {
        winner = winning_board[0][0];
        return winner;
        cout << " WON THE GAME";
    }

    if (winning_board[0][2] == winning_board[1][1] && winning_board[1][1] == winning_board[2][0] && winning_board[0][2] != "  ") {
        winner = winning_board[0][2];
        return winner;
        cout << " WON THE GAME";
    }

    return "No Winner";
}


// We want to play the move that gives X the highest possible score
int minimax(vector<vector<string> > board, bool maximizedPlayer) {
    string winner = getWinner(board);
    map<string, int> scoreMap;
   
   // Assigning values to the 3 different outcomes of the game
    scoreMap[" X "] = 1;
    scoreMap[" 0 "] = -1;
    scoreMap["tie"] = 0;

    // If the game is over, we return the evaluation score of that game
    if (winner != "No Winner") {
        int score = scoreMap[winner];
        return score;
    }
    
    // If the game is not over, we first check if the currrent player is the maximizing one
    if (maximizedPlayer) {

        // If it is, we start by initializing bestScore with int min, so we can store the higher number
        int bestScore = numeric_limits<int>::min();

        // Loop through each row and column of the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {

                // For EACH empty cell, place the current player's marker there
                if (board[i][j] == "  ") {
                    board[i][j] = " X ";

                    // After placing the marker, minimax is called with the updated board 
                    // The result of this recursive call (on every empty space) is stored in score
                    // It plays out a full game from each position, and returns either 0, 1, or -1.
                    int score = minimax(board, false);

                    // Clear the space we just modified
                    board[i][j] = "  ";

                    // The highest score gets saved
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;

        // Minimizing player
    } else {

        // Initialize bestScore with int max so we can store the lower number
       int bestScore = numeric_limits<int>::max();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(i).size(); j++) {
                if (board[i][j] == "  ") {

                    // Place marker on empty space
                    board[i][j] = "0";

                    // Call minimax on the updated board, scoring all possible game states from every empty square
                    int score = minimax(board, true);
                    board[i][j] = "  ";

                    // Assuming 0 plays optimally means we want to take the lower score
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }

    
}

// X is the AI player, which we want to maximize. This function grabs the coordinates of the best move 
    // according to minimax
    
vector<int> bestMoveX(vector<vector<string> > board, string player) {
    int bestScore = numeric_limits<int>::min();
    vector<int> move;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(i).size(); j++) {
            if (board[i][j] == "  ") {
                board[i][j] = "X";

                // Call the minimax function with different possible moves
                int score = minimax(board, false);
                board[i][j] = "  ";

                // Push back the indices of the best score for X
                if (score > bestScore) {
                    bestScore = score;
                    move.clear();
                    move.push_back(i);
                    move.push_back(j);
                }
            }
        }
    }
    return move;
}

int main() {
    vector<vector<string> > gameBoard = clean_board();
    int count = 0;
    int turns = 0;
    string winner;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "You are 0, and the AI is X." << endl;

    while (true) {
        vector<int> move_coords;
        render(gameBoard);
        winner = getWinner(gameBoard);
        cout << winner << endl;

        if (winner != "No Winner") {
            break;
        }

        // Make sure turns are alternated, with X starting first
        if (count % 2 == 0) {
            // Store optimal coordinates for AI's move
            move_coords = bestMoveX(gameBoard, " X "); 
        } else {
            // Store inputted coordinates from human player
            move_coords = get_move();  
        }

        bool validMove = is_valid_move(gameBoard, move_coords);

        // Place marker
        if (validMove) {
            turns++;
            if (count % 2 == 0) {
                gameBoard = make_move(gameBoard, move_coords, " X ");
            } else {
                gameBoard = make_move(gameBoard, move_coords, " 0 ");
            }
            count++;
        } else {
            continue;
        }

        // If board is filled and there is no winner, return "tie"
        if (count == 9) {
            winner.clear();
            cout << "tie" << endl;
            break;
        }
        
    }

    return 0;
}