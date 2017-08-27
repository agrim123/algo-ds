/*
 * Longest Increasing Subsequence
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

// Time Complexity: O(n^2)
int longest_increasing_subsequence( int arr[], int n ) {
    int lis[n];

    // Initialize LIS values for all indexes
    for (int i = 0; i < n; i++ )
        lis[i] = 1;

    // Compute optimized LIS values in bottom up manner
    for (int i = 1; i < n; i++ )
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    // Pick maximum of all LIS values
    int max = 0;
    for (int i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    return max;
}

int main() {
    int arr[] = { 51, 22, 9, 33, 54, 2, 12, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of LIS is "<<longest_increasing_subsequence(arr, n)<<endl;
    return 0;
}
