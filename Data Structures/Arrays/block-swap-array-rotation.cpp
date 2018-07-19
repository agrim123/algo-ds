// Block Swap Array Rotation
// Iterative Implementation
// Time Complexity: O(n)

#include <iostream>

using namespace std;

// This function swaps d elements starting at index f with d elements starting at index s
void swap(int arr[], int f, int s, int d) {
  int temp;
  for(int i = 0; i<d; i++) {
    temp = arr[f + i];
    arr[f + i] = arr[s + i];
    arr[s + i] = temp;
  }
}

void leftRotate(int arr[], int d, int n) {
  if(d == 0 || d == n)
    return;

  int i = d, j = n - d;

  while (i != j) {
    if(i < j) {
      swap(arr, d-i, d+j-i, i);
      j -= i;
    } else {
      swap(arr, d-i, d, j);
      i -= j;
    }
  }

  swap(arr, d-i, d, i);
}

void display(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout<<" "<<arr[i];
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  int d = 2; // Left Rotate by 2
  leftRotate(arr, d, n);
  display(arr, n);
  return 0;
}
