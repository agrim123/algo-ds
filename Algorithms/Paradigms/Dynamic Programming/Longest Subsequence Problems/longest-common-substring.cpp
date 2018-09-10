/*
 * Longest Increasing Subsequence
 *
 */

#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(m*n)
int lcs(string A, string B) {
    int n = A.size(), m = B.size();
    int L[n+1][m+1];

    int res = 0;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (A[i-1] == B[j-1]) {
                L[i][j] = L[i-1][j-1]+1;
                res = max(res, L[i][j]);
            } else L[i][j] = 0;
        }
    }
    return res;
}

int main() {
    cout<<"Length of LCS is "<<lcs("random", "word")<<endl;
    return 0;
}
