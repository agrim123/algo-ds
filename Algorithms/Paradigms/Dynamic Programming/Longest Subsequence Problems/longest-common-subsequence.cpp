#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(2^n)
int lcs_recur(string a, string b, int i, int j) {
    if (i == 0 || j == 0) return 0;

    if (a[i-1] == b[j-1]) return lcs_recur(a, b, i-1, j-1) + 1;

    return max(lcs_recur(a, b, i, j-1), lcs_recur(a, b, i-1, j));
}

// Time Complexity: O(nm)
void lcs_mem(string a, string b) {
    int n = a.size(), m = b.size();
    int L[n+1][m+1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0) L[i][j] = 0;

            else if (a[i-1] == b[j-1]) L[i][j] = L[i-1][j-1] + 1;

            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    cout<<"Length of LCS is "<<L[n][m]<<endl;

    int index = L[n][m];
    char lcs[index+1];
    lcs[index] = '\0';

    int i = n, j = m;

    while(i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs[index-1] = a[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j] > L[i][j-1]) i--;
        else j--;
    }

    cout<<"LCS is "<<lcs<<endl;
}

int main() {
    string a = "ABCDGH";
    string b = "AEDFHR";
    cout<<lcs_recur(a, b, a.size(), b.size())<<endl;
    lcs_mem(a, b);
    return 0;
}
