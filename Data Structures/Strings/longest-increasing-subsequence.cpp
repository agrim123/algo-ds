/*
 * Longest Increasing Subsequence
 *
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Time Complexity: O(n^2)
int longest_increasing_subsequence(vector<int> A) {
    int n = A.size();

    if (n <= 1)
        return n;

    vector<int> ans(n, 1);
    int sol = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                ans[i] = max(ans[j]+1, ans[i]);

                if (ans[i] > sol)
                    sol = ans[i];
            }
        }
    }

    return sol;
}

int main() {
    cout<<"Length of LIS is "<<longest_increasing_subsequence({ 51, 22, 9, 33, 54, 2, 12, 60 })<<endl;
    return 0;
}
