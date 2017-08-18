/*
 * Pigeonhole Sort
 *
 */

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp);

void printArray(int arr[], int size);

void pigeonholeSort(int arr[], int n) {
    // Find minimum and maximum values in arr[]
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1;

    // Create an array of vectors. Size of array range. Each vector represents a hole that is going to contain matching elements.
    vector<int> holes[range];

    // Traverse through input array and put every element in its respective hole
    for (int i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);

    // Traverse through all holes one by one. For every hole, take its elements and put in array.
    int index = 0;  // index in sorted array
    for (int i = 0; i < range; i++) {
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++]  = *it;
    }
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3,1,5,2,75,712,35,541,256,24,57353};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Pigeon Hole Sort => ";
    pigeonholeSort(arr, n);
    printArray(arr, n);
    return 0;
}
