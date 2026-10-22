#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = currentMarker;
    return true;
}

int checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();
    int winner = 0;
    for (int i = 0; i < 9 && winner == 0; i++) {
        cout << "Player " << currentPlayer << ", choose your slot (1-9): ";
        int slot;
        cin >> slot;

        if (!placeMarker(slot)) {
            cout << "Slot taken or invalid! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        winner = checkWinner();
        if (winner == 0) switchPlayer();
    }

    if (winner == 0) cout << "It's a Draw!\n";
    else cout << "?? Player " << winner << " Wins!\n";

    return 0;
}

