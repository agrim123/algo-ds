/*
 * Longest Common Subsequence
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Time Complexity: O(nm)
int lcs(string A, string B) {
    int m = A.size(), n = B.size();
    int L[m+1][n+1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (A[i-1] == B[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[m][n];
}

int main() {
    cout<<"Length of LCS is "<<lcs("random", "string")<<endl;
    return 0;
}
