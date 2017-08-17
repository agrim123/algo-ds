/*
 * Jump Search
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int jumpSearch(int arr[], int n, int x) {
    // Finding block size to be jumped
    int step = (int)floor(sqrt(n));

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n)-1] < x) {
        prev = step;
        step += (int)floor(sqrt(n));
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x) {
        prev++;

        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }

    // If element is found
    if (arr[prev] == x)
        return prev;

    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3,5,12,56,92,123,156,190,201,222};
    int a = 12;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Jump Search :: "<<jumpSearch(arr, n, a)<<endl;
    return 0;
}
