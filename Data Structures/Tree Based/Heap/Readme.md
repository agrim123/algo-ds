# Heap

Heap is a special case of balanced binary tree data structure where the root-node key is compared with its children and arranged accordingly.  
It has following properties  

1. It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.
2. A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap.


## Types of Heap

1. **Min-Heap** : Where the value of the root node is less than or equal to either of its children.
2. **Max-Heap** : Where the value of the root node is greater than or equal to either of its children.

## Applications of Heaps:

1) **[Heap Sort](/Algorithms/Sorting/Heap%20Sort)**: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) **[Priority Queue](/Data%20Structures/Queue/Priority%20Queue)**: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) **[Graph Algorithms](/Data%20Structures/Graph)**: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

## Time Complexity

Worst case Time Complexity is `O(nLogn)`

## References


- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Heap](https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm)
