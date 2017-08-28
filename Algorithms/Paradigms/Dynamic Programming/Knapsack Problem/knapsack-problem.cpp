/*
 * 0-1 Knapsack Problem
 *
 */

#include <iostream>

using namespace std;

int max(int a, int b) {
    return (a > b)? a : b;
}

int knapsack_recursive(int W, int wt[], int val[], int n) {
   if (n == 0 || W == 0)
       return 0;

   if (wt[n-1] > W)
       return knapsack_recursive(W, wt, val, n-1);
   else return max( val[n-1] + knapsack_recursive(W-wt[n-1], wt, val, n-1), knapsack_recursive(W, wt, val, n-1));
}

// Time Complexity: O(nW)
int knapsack_dp(int W, int wt[], int val[], int n) {
    int K[n+1][W+1];
    for (int i = 0; i <= n; i++) {
       for (int j = 0; j <= W; j++) {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
    }
    return K[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 60;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack_recursive(W, wt, val, n)<<endl;
    cout<<knapsack_dp(W, wt, val, n)<<endl;
}
