# Linked Lists

A linked list is a sequence of data structures, which are connected together via links.  

Linked lists are among the simplest and most common data structures. They can be used to implement several other common abstract data types, including lists (the abstract data type), stacks, queues, associative arrays, and S-expressions, though it is not uncommon to implement the other data structures directly without using a list as the basis of implementation.  

Linked lists have worst-case `O(1)`-time appends, which is better than the worst-case `O(n)` time of dynamic arrays.

## Types of Linked List

- **Singly Linked List** − Item navigation is forward only.

- **Doubly Linked List** − Items can be navigated forward and backward.

- **Circular Linked List** − Last item contains link of the first element as next and the first element has a link to the last element as previous.

## Basic Operations

- **Insertion** − Adds an element at the beginning of the list.

- **Deletion** − Deletes an element at the beginning of the list.

- **Insert Last** − Adds an element at the end of the list.

- **Delete Last** − Deletes an element from the end of the list.

- **Insert After** − Adds an element after an item of the list.

- **Delete** − Deletes an element from the list using the key.

- **Display forward** − Displays the complete list in a forward manner.

- **Display backward** − Displays the complete list in a backward manner.


## Advantages

1) Dynamic Size
2) Ease of insertion/deletion of elements
3) Backtracking is possible in two way linked list.

## Drawbacks

1) Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists.
2) Extra memory space for a pointer is required with each element of the list.


## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Linked List](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)
