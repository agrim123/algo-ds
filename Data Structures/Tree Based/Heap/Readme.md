# Heap

Heap is a special case of balanced binary tree data structure where the root-node key is compared with its children and arranged accordingly.  
It has following properties  

1. It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.
2. A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap.
3. Perfect balanced tree.


## Types of Heap

1. **[Min-Heap](Min%20Heap)** : Where the value of the root node is less than or equal to either of its children.
2. **[Max-Heap](Max%20Heap)** : Where the value of the root node is greater than or equal to either of its children.

## Applications of Heaps:

1) **[Heap Sort](/Algorithms/Sorting/Heap%20Sort)**: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) **[Priority Queue](/Data%20Structures/Queue/Priority%20Queue)**: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) **[Graph Algorithms](/Data%20Structures/Graph)**: The priority queues are especially used in Graph Algorithms like [Dijkstra’s Shortest Path](/Data%20Structures/Graph/Shortest%20Path%20Algorithms/Dijkstra%27s%20Algorithm) and [Prim’s Minimum Spanning Tree](/Data%20Structures/Graph/Spanning%20Tree/Prim%E2%80%99s%20Algorithm).

4) Some problems
    - kth largest element in an array.
    - Merge k sorted arrays.

## Accessing elements

```cpp
Parent(i)
    return i/2;

Left(i)
    return 2i;

Right(i)
    return 2i+1; 
```

## Common procedures

1) Max-Heapify - O(logn)
2) Build-Max-Heap - O(n)
3) HeapSort - O(nlogn)
4) Max-Heap-Insert, Heap-Extract-Max, Heap-Increase-Key, Heap-Maximum - O(logn), allows heap data structure to implement priority queue.

## Standard Properties of Heap

- For a heap of height `h`, maximum number of elements in a heap can be `2^(h+1)-1` and minimum can be `2^h`.
- A `n` element heap has height `logn`.
- The smallest element resides in the leaf node.
- 

## Time Complexity

Worst case Time Complexity is `O(nLogn)`

## References


- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Heap](https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm)
- http://net.pku.edu.cn/~course/cs101/2007/resource/Intro2Algorithm/book6/chap07.htm
