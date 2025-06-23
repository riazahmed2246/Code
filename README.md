# Code

N queen 
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // Check vertical column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueen(vector<vector<int>> &board, int row, int n) {
    if (row == n)
        return true;  // all queens placed

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // place queen

            if (solveNQueen(board, row + 1, n))
                return true; // if solution found, return

            board[row][col] = 0; // backtrack
        }
    }
    return false; // no safe position found
}

void printBoard(const vector<vector<int>> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueen(board, 0, n))
        printBoard(board, n);
    else
        cout << "No solution exists for " << n << " queens." << endl;

    return 0;
}

