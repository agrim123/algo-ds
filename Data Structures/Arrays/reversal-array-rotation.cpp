// Reversal algorithm of array rotation
// function rotate(arr[], d, n) that rotates arr[] of size n by d elements.
// Time complexity : O(n)

#include <iostream>

using namespace std;

void reverseArray(int arr[], int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int d, int n) {
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}


void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout<<" "<<arr[i];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    leftRotate(arr, d, n);
    display(arr, n);
    return 0;
}
