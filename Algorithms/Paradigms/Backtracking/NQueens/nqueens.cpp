/*
    The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other
 */

#include <bits/stdc++.h>

using namespace std;

void printSol(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>& board, int row, int column, int N) {
    int i, j;

    // check on left side of the column in this row
    for (int i = 0; i < column; ++i)
        if (board[row][i])
            return false;

    // check upper diagnol on left side
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left sid
    for (i = row, j = column; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveUtil(vector<vector<int>>& board, int column, int N) {
    // base case: If all queens are placed
    if (column >= N)
        return true;

    // for this column try placing queen in all rows
    for (int i = 0; i < N; ++i)
    {
        // check if queen can be placed at board[i][col]
        if (isSafe(board, i, column, N)) {
            // place queen at (i, column)
            board[i][column] = 1;

            // recur to place other queens
            if (solveUtil(board, column + 1, N))
                return true;

            // if placing queen in board[i][col] does not give a solution
            // then remove queen from the board and backtrack
            board[i][column] = 0;
        }
    }

    // if queen cannot be placed in any row in this column
    return false;
}

void solve(int N) {
    vector<vector<int>> board;

    if (N == 2 || N == 3)
        return;

    vector<int> temp(N, 0);

    for (int i = 0; i < N; ++i)
        board.emplace_back(temp);

    solveUtil(board, 0, N);
    printSol(board);
}

int main() {
    solve(4);
}
