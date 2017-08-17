/*
 * Linear Search
 *
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int linearSearch(int arr[], int n, int a) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == a)
            return i;

    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3,5,12,56,92,123,156,190,201,222};
    int a = 12;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Linear Search :: "<<linearSearch(arr, n, a)<<endl;
    return 0;
}
