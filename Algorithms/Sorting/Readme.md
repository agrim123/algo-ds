## Sorting Algorithms

```
Sort a given array arr[] in ascending or descending order.
```

- **[Selection Sort](Selection%20Sort)**
  - The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array :  
        1) The subarray which is already sorted.
        2) Remaining subarray which is unsorted.

  - In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
  - Time Complexity: `O(n^2)` as there are two nested loops
  - Auxiliary Space: `O(1)`
- **[Bubble Sort](Bubble%20Sort)**
  - Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
  - Best Case Time Complexity: `O(n)`. Best case occurs when array is already sorted.
  - Worst and Average Case Time Complexity: `O(n*n)`. Worst case occurs when array is reverse sorted.
  - Auxiliary Space: `O(1)`
- **[Insertion Sort](Insertion%20Sort)**
  - Time Complexity: `O(n*n)`
  - Best Case Time Complexity: `O(n)`. Best case occurs when array is already sorted.
  - Auxiliary Space: `O(1)`
  - Algorithmic Paradigm: Incremental Approach
  - Sorting In Place: Yes
  - **Uses**: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
- **[Quick Sort](Quick%20Sort)**
   - QuickSort is a Divide and Conquer algorithm. 
   - It picks an element as pivot and partitions the given array around the picked pivot.
   - Time Complexity
      - Worst Case :`O(n^2)`
      - Best Case : `O(nLogn)`
   - Quick Sort is preferred over MergeSort for sorting Arrays
   - MergeSort is preferred over QuickSort for Linked Lists
- **[Merge Sort](Merge%20Sort)**
  - Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
  - The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
  - Time complexity of Merge Sort is `O(nLogn)`
  - Auxiliary Space: `O(n)`
  - Algorithmic Paradigm: Divide and Conquer
  - Merge Sort is useful for sorting linked lists in O(nLogn) time
- **[Heap Sort](Heap%20Sort)**
  - Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.
  - Time Complexity : `O(nLogn)`
- **[Shell Sort](Shell%20Sort)**
  - ShellSort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element is sorted.
  - Time Complexity : Time complexity of above implementation of shellsort is `O(n^2)`.

## References

- [Articles on Sorting](http://www.geeksforgeeks.org/sorting-algorithms/)
