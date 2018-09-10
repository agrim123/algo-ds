/*
 * Longest Palindromic Subsequence
 *
 */

#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n^2)
int lps(string A) {
    int n = A.size();
    int L[n][n] = {0};

    for (int i = 0; i < n; ++i)
        L[i][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n-i+1; j++)
        {
            int k = j+i-1;
            if (A[j] == A[k] && i == 2) L[j][k] = 2;
            else if (A[j] == A[k]) L[j][k] = L[j+1][k-1] + 2;
            else L[j][k] = max(L[j+1][k], L[j][k-1]);
        }
    }
    return L[0][n-1];
}

int main() {
    cout<<lps("qwiugeqiuuiq")<<endl;
    return 0;
}
