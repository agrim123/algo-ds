## Searching Algorithms

```
Given an array arr[] of n elements. Write a function to search a given element x in arr[].
```

- **Linear Search**
  - The time complexity of above algorithm is `O(n)`.
  - Auxiliary Space : `O(1)`
  - Linear search is rarely used practically because other search algorithms such as the binary search algorithm and hash tables allow significantly faster searching comparison to Linear search.
- **Binary Search**
  -  Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
  - Time complexity to `O(Logn)`
  - Auxiliary Space : `O(1)`
- **Jump Search**
  - The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements.
  - Time Complexity : `O(√n)`.
  - Auxiliary Space : `O(1)`.
- **Interpolation Search**
  - Given array is uniformly distributed.
  - The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Binary Search always goes to middle element to check. On the other hand interpolation search may go to different locations according the value of key being searched. For example if the value of key is closer to the last element, interpolation search is likely to start search toward the end side.
  - Time Complexity : If elements are uniformly distributed, then `O (log log n))`. In worst case it can take upto `O(n)`.
  - Auxiliary Space : `O(1)`
- **Exponential Search**
  - Exponential search involves two steps:  
       1. Find range where element is present
       2. Do Binary Search in above found range.
  - Time Complexity : `O(Log n)`
  - Auxiliary Space : The above implementation of Binary Search is recursive and requires `O(Log n)` space. With iterative Binary Search, we need only `O(1)` space. 
- **Fibonacci Search**
  - Given a sorted array.
  -  Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.
  -  Fibonacci Search divides given array in unequal parts
  - Algorithmic Paradigm: Divide and Conquer Algorithm.
  - Time Complexity : `O(Log n)`.
- **Sublist Search** ***(Search a linked list in another list)***
  - Given two linked lists, the task is to check whether the first list is present in 2nd list or not.
  - Time Complexity : `O(m*n)` where m is the number of nodes in second list and n in first.

## References

- [Articles on Searching](http://www.geeksforgeeks.org/searching-algorithms)
