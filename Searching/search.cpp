#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

// Time Complexity :: O(n)
// Auxiliary Space : O(1)
int linearSearch(int arr[], int n, int a) {
    for (int i = 0; i < n; ++i){
      if (arr[i] == a) {
        return i;
    }
}
return -1;
}

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
// Time Complexity :: O(log n)
// Auxiliary Space : O(1)
int binarySearch(int arr[], int l, int r, int x){
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        // If the element is present at the middle itself
        if (arr[mid] == x) return mid;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
    }

   // We reach here when element is not present in array
    return -1;
}

// Time Complexity :: O(√n)
// Auxiliary Space : O(1)

int jumpSearch(int arr[], int n, int x){
    // Finding block size to be jumped
    int step = (int)floor(sqrt(n));

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += (int)floor(sqrt(n));
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
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

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
// Time Complexity :: O (log log n))
// Auxiliary Space : O(1)
int interpolationSearch(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi-lo) /
              (arr[hi]-arr[lo]))*(x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;
 
        // If x is smaller, x is in lower part
        else
            hi = pos - 1;
    }
    return -1;
}

// Returns position of first ocurrence of
// x in array
// Time Complexity : O(Log n)
// Auxiliary Space : The above implementation of Binary Search is recursive and requires O()Log n) space. With iterative Binary Search, we need only O(1) space.
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n), x);
}

int fibonacciSearch(int arr[], int n, int x)
{
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci
 
    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }
 
    // Marks the eliminated range from front
    int offset = -1;
 
    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1)
    {
        // Check if fibMm2 is a valid location
        int i = min(offset+fibMMm2, n-1);
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* element found. return index */
        else return i;
    }
 
    /* comparing the last element with x */
    if(fibMMm1 && arr[offset+1]==x)return offset+1;
 
    /*element not found. return -1 */
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,5,12,56,92,123,156,190,201,222};
    int a = 12;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Linear Search :: "<<linearSearch(arr, n, a)<<endl;
    cout<<"Binary Search :: "<<binarySearch(arr, 0, n-1, a)<<endl;
    cout<<"Jump Search :: "<<jumpSearch(arr, n, a)<<endl;
    cout<<"Interpolation Search :: "<<interpolationSearch(arr, n, a)<<endl;
    cout<<"Exponential Search :: "<<exponentialSearch(arr, n, a)<<endl;
    cout<<"Fibonacci Search :: "<<fibonacciSearch(arr, n, a)<<endl;
    return 0;
}