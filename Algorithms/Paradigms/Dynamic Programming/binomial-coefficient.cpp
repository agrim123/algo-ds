/*
 * Binomial Coefficient C(n, k)
 *
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int binomial_coefficient_recursive(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomial_coefficient_recursive(n-1, k-1) + binomial_coefficient_recursive(n-1, k);
}

// Bottom-up Manner
// Time Complexity: O(n*k)
// Auxiliary Space: O(n*k)
int binomial_coefficient_dp_1(int n, int k) {
    int C[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

// Space efficient
// Time Complexity: O(n*k)
// Auxiliary Space: O(k)
int binomial_coefficient_dp_2(int n, int k) {
    int C[k+1];
    // Fill array with 0
    memset(C, 0, sizeof(C));

    C[0] = 1;  // C(n, 0) = 1

    for (int i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }

    return C[k];
}

int main() {
    cout<<binomial_coefficient_recursive(6, 2)<<endl;
    cout<<binomial_coefficient_dp_1(6, 2)<<endl;
    cout<<binomial_coefficient_dp_2(6, 2)<<endl;
    return 0;
}
