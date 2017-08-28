/*  Knight's tour
    - A knight's tour is a sequence of moves of a knight on a chessboard such that the knight visits every square only once. If the knight ends on a square that is one knight's move from the beginning square (so that it could tour the board again immediately, following the same path), the tour is closed, otherwise it is open.
    The knight's tour problem is the mathematical problem of finding a knight's tour.
    - Possible Solutions
        a. Brute-Force
        b. Divide and Conquer
        c. Warnsdorf's rule (more efficient than backtracking)
*/

#include <iostream>

using namespace std;

#define N 8

int solve_knight_tour_util(int x, int y, int movei, int sol[N][N], int xMove[],  int yMove[]);

// Function to check if i,j are valid indexes for N*N chessboard
bool is_safe(int x, int y, int sol[N][N]) {
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == -1);
}

// Function to print solution matrix sol[N][N]
void print_solution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout<<"  "<<sol[x][y];
        cout<<endl;
    }
}

/* This function solves the Knight Tour problem using
   Backtracking.  This function mainly uses solve_knight_tour_util()
   to solve the problem. It returns false if no complete
   tour is possible, otherwise return true and prints the
   tour.
   There may be more than one solutions, this function prints one of the feasible solutions.  */
bool solve_knight_tour() {
    int sol[N][N];

    // Initialization of solution matrix
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    // Since the Knight is initially at the first block
    sol[0][0]  = 0;

    /* Start from 0,0 and explore all tours using
       solve_knight_tour_util() */
    if (solve_knight_tour_util(0, 0, 1, sol, xMove, yMove) == false) {
        cout<<"Solution does not exist";
        return false;
    }
    else
        print_solution(sol);

    return true;
}

// A recursive utility function to solve Knight Tour problem
int solve_knight_tour_util(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]) {
   int k, next_x, next_y;
   if (movei == N*N)
       return true;

   // Try all next moves from the current coordinate x, y
   for (k = 0; k < 8; k++) {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (is_safe(next_x, next_y, sol)) {
         sol[next_x][next_y] = movei;
         if (solve_knight_tour_util(next_x, next_y, movei+1, sol, xMove, yMove) == true)
             return true;
         else
             sol[next_x][next_y] = -1; // backtracking
       }
   }

   return false;
}

int main() {
    solve_knight_tour();
    return 0;
}
