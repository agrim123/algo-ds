/*
 * Insertion Sort
 *
 */

#include <iostream>

using namespace std;

void printArray(int arr[], int size);

int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printArray(arr, n);
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int main(int argc, char const *argv[]) {
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Insertion Sort => ";
    insertionSort(arr, n);
    return 0;
}
