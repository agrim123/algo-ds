/*
 * Interpolation Search
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = (n - 1);

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = low + (((double)(high-low) /
              (arr[high]-arr[low]))*(x - arr[low]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in upper part
        if (arr[pos] < x)
            low = pos + 1;

        // If x is smaller, x is in lower part
        else
            high = pos - 1;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3,5,12,56,92,123,156,190,201,222};
    int a = 12;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Interpolation Search :: "<<interpolationSearch(arr, n, a)<<endl;
    return 0;
}
