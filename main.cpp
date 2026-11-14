// Tic-Tac-Toe Game (Console-based, 2 Players)
// Language: C++

#include <iostream>
#include <limits>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    int winsX, winsO, ties;

public:
    TicTacToe() : winsX(0), winsO(0), ties(0) {
        resetBoard();
    }

    // Fill the board with positions 1-9 and set Player 1 (X) to start
    void resetBoard() {
        char pos = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = pos++;
        currentPlayer = 'X';
    }

    void displayBoard() const {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "     ";
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "     ---+---+---\n";
        }
        cout << "\n";
    }

    void displayScore() const {
        cout << "---------- SCOREBOARD ----------\n";
        cout << "Player 1 (X): " << winsX << "\n";
        cout << "Player 2 (O): " << winsO << "\n";
        cout << "Ties        : " << ties << "\n";
        cout << "--------------------------------\n";
    }

    // Validate and place a move. Returns false if the move is invalid.
    bool makeMove(int position) {
        if (position < 1 || position > 9) return false;

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') return false;

        board[row][col] = currentPlayer;
        return true;
    }

    // Check all 3 rows, 3 columns and 2 diagonals
    bool checkWin() const {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        return false;
    }

    // Tie if every cell is taken (call after checkWin returns false)
    bool checkTie() const {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    int playerNumber() const {
        return (currentPlayer == 'X') ? 1 : 2;
    }

    // Play one full round
    void playRound() {
        resetBoard();

        while (true) {
            displayBoard();
            cout << "Player " << playerNumber() << " (" << currentPlayer
                 << ") - enter position (1-9): ";

            int position;
            if (!(cin >> position)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
                continue;
            }

            if (!makeMove(position)) {
                cout << "Invalid move! Position is out of range or already taken.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "*** Player " << playerNumber() << " (" << currentPlayer
                     << ") wins! ***\n";
                if (currentPlayer == 'X') winsX++;
                else winsO++;
                break;
            }

            if (checkTie()) {
                displayBoard();
                cout << "*** It's a tie! ***\n";
                ties++;
                break;
            }

            switchPlayer();
        }
    }

    void run() {
        char choice;
        cout << "=====================================\n";
        cout << "       TIC-TAC-TOE (2 PLAYERS)       \n";
        cout << "=====================================\n";
        cout << "Player 1 uses X, Player 2 uses O.\n";
        cout << "Get three of your symbols in a row to win!\n";

        do {
            playRound();
            displayScore();
            cout << "Play again? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "\nThanks for playing! Final scores:\n";
        displayScore();
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
