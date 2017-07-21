#include <iostream>
#include <cstdio>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Time Complexity: O(n2) as there are two nested loops.
// Auxiliary Space: O(1)
int selectionSort() {
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Selection Sort => ";
    int m;
    for (int i = 0; i < n-1; ++i){
        m = i;
        for (int j= i+1; j < n; ++j)
            if (arr[j] < arr[m])
                m = j;
        swap(&arr[m], &arr[i]);
    }
    printArray(arr, n);
}

// Time Complexity: O(n*n)
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
int bubbleSort() {
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Bubble Sort => ";
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-i-1; ++j)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    printArray(arr, n);
}

// Time Complexity: O(n*n)
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Algorithmic Paradigm: Incremental Approach
// Sorting In Place: Yes
// Stable: Yes
// Online: Yes
// Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
int insertionSort() {
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Insertion Sort => ";
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

// Time Complexity :: Theta(nLogn)
// Auxiliary Space: O(n)
// Algorithmic Paradigm: Divide and Conquer
// Sorting In Place: No in a typical implementation
// Stable: Yes
// Merge Sort is useful for sorting linked lists in O(nLogn) time
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// Time Complexity :: O(nLogn).
// Heap sort is an in-place algorithm.
// Its typical implementation is not stable
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Radix Sort
// What is the running time of Radix Sort?
// Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers, for example, for decimal system, b is 10. What is the value of d? If k is the maximum possible value, then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison based sorting algorithms for a large k. Let us first limit k. Let k <= nc where c is a constant. In that case, the complexity becomes O(nLogb(n)). But it still doesn’t beat comparison based sorting algorithms.
// What if we make value of b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we get the time complexity as O(n). In other words, we can sort an array of integers with range from 1 to nc if the numbers are represented in base n (or every digit takes log2(n) bits).
// Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort?
// If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int radixSort() {
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Radix Sort => ";
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);

    printArray(arr, n);
}

// Time Complexity: Time complexity of above implementation of shellsort is O(n2). In the above implementation gap is reduce by half in every iteration. There are many other ways to reduce gap which lead to better time complexity. 
int shellSort()
{
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Shell Sort => ";
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    printArray(arr, n);
}

void pigeonholeSort()
{
    int arr[] = {2,5,2,34574,23,24735,35,47,3523,5893,21,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Shell Sort => ";
    // Find minimum and maximum values in arr[]
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1; // Find range

    // Create an array of vectors. Size of array
    // range. Each vector represents a hole that
    // is going to contain matching elements.
    vector<int> holes[range];

    // Traverse through input array and put every
    // element in its respective hole
    for (int i = 0; i < n; i++)
        holes[arr[i]-min].push_back(arr[i]);

    // Traverse through all holes one by one. For
    // every hole, take its elements and put in
    // array.
    int index = 0; // index in sorted array
    for (int i = 0; i < range; i++)
    {
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++] = *it;
    }
    printArray(arr, n);
}

int main(int argc, char const *argv[])
{
    selectionSort();
    bubbleSort();
    insertionSort();
    int arr[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Merge Sort => ";
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    cout<<"Quick Sort => "<<endl;
    int arr1[] = {3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout<<"Heap Sort => ";
    heapSort(arr1, n1);
    printArray(arr1, n1);
    // Stability of Algorithm => http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/stability.pdf
    // https://en.wikipedia.org/wiki/Sorting_algorithm#Stability
    cout<<"Counting Sort => "<<endl;
    cout<<"Bucket Sort => "<<endl;
    // Comb Sort (improvement over Bubble Sort)
    radixSort();
    shellSort();
    return 0;
}