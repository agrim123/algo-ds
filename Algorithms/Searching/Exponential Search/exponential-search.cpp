/*
 * Exponential Search
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l)/2;

        // If the element is present at the middle itself
        if (arr[mid] == x) return mid;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;

    // Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n), x);
}

int main(int argc, char const *argv[]) {
    int arr[] = {3,5,12,56,92,123,156,190,201,222};
    int a = 12;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Exponential Search :: "<<exponentialSearch(arr, n, a)<<endl;
    return 0;
}
