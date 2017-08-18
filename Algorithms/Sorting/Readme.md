## Sorting Algorithms

```
Sort a given array arr[] in ascending or descending order.
```

- **Selection Sort**
  - The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array :  
        1) The subarray which is already sorted.
        2) Remaining subarray which is unsorted.

  - In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
  - Time Complexity: `O(n^2)` as there are two nested loops
  - Auxiliary Space: `O(1)`
- **Bubble Sort**
  - Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
  - Best Case Time Complexity: `O(n)`. Best case occurs when array is already sorted.
  - Worst and Average Case Time Complexity: `O(n*n)`. Worst case occurs when array is reverse sorted.
  - Auxiliary Space: `O(1)`
- **Insertion Sort**
  - Time Complexity: `O(n*n)`
  - Best Case Time Complexity: `O(n)`. Best case occurs when array is already sorted.
  - Auxiliary Space: `O(1)`
  - Algorithmic Paradigm: Incremental Approach
  - Sorting In Place: Yes
  - **Uses**: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
- **Quick Sort**
   - QuickSort is a Divide and Conquer algorithm. 
   - It picks an element as pivot and partitions the given array around the picked pivot.
   - Time Complexity
      - Worst Case :`O(n^2)`
      - Best Case : `O(nLogn)`
   - Quick Sort is preferred over MergeSort for sorting Arrays
   - MergeSort is preferred over QuickSort for Linked Lists
- **Merge Sort**
  - Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
  - The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
  - Time complexity of Merge Sort is `O(nLogn)`
  - Auxiliary Space: `O(n)`
  - Algorithmic Paradigm: Divide and Conquer
  - Merge Sort is useful for sorting linked lists in O(nLogn) time
- **Heap Sort**
  - Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.
  - Time Complexity : `O(nLogn)`
- **Counting Sort**
  - Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.
  -  It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
  -  Counting sort can be extended to work for negative inputs also.
  - Time Complexity: `O(n+k)` where n is the number of elements in input array and k is the range of input.
  - Auxiliary Space: `O(n+k)`
- **Radix Sort**
  - The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
  - Let there be d digits in input integers. Radix Sort takes `O(d*(n+b))` time where b is the base for representing numbers
- **Shell Sort**
  - ShellSort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element is sorted.
  - Time Complexity : Time complexity of above implementation of shellsort is `O(n^2)`.
- **Pigeonhole Sort**
  - Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements where the number of elements and the number of possible key values are approximately the same.
  - It is similar to counting sort, but differs in that it “moves items twice: once to the bucket array and again to the final destination “.
  - Time Complexity : `O(n + Range)` time where n is number of elements in input array and ‘Range’ is number of possible values in array.

## References

- [Articles on Searching](http://www.geeksforgeeks.org/sorting-algorithms/)
