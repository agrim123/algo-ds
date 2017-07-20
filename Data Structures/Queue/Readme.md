# Queues

Queue is an abstract data structure, somewhat similar to Stacks. Unlike stacks, a queue is open at both its ends. One end is always used to insert data (enqueue) and the other is used to remove data (dequeue). Queue follows First-In-First-Out methodology, i.e., the data item stored first will be accessed first.

## Basic Operations

Queue operations may involve initializing or defining the queue, utilizing it, and then completely erasing it from the memory. Basic operations associated with queues −

- **enqueue()** − add / store an item to the queue.

- **dequeue()** − remove / access an item from the queue.

- **peek()** − Gets the element at the front of the queue without removing it.

- **isfull()** − Checks if the queue is full.

- **isempty()** − Checks if the queue is empty.

In queue, we always dequeue (or access) data, pointed by front pointer and while enqueing (or storing) data in the queue we take help of rear pointer.

## Time Complexities of operations on stack:

push(), pop(), isEmpty() and peek() all take O(1) time as no loop is run in any of these operations.

## Applications of Queue

Queue is used when things don’t have to be processed immediatly, but have to be processed in First In First Out order.

1) When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling.
2) When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Queue](https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm)