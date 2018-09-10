/*
 * Longest Palindromic Substring
 *
 */

#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n^2)
// Auxiliary Space: O(n^2)
string lps(string A) {
    int n = A.size();
    bool L[n][n] = {false};

    // for substrings of length 1
    for (int i = 0; i < n; ++i)
        L[i][i] = true;

    int start = 1, maxLength = 1;

    // for substrings of length 2
    for (int i = 0; i < n-1; ++i)
    {
        if (A[i] == A[i+1]) {
            L[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int i = 3; i <= n; ++i)
    {
        for (int j = 0; j < n-i+1; ++j)
        {
            int k = i+j-1;
            if (L[j+1][k-1] && A[j] == A[k]) {
                L[j][k] = true;
                if (i > maxLength) {
                    start = j;
                    maxLength = i;
                }
            }
        }
    }

    return A.substr(start, start+maxLength-1);
}

int main() {
    cout<<lps("babad")<<endl;
    return 0;
}
