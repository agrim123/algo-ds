# Min Heap

> Where the value of the root node is less than or equal to either of its children.

```cpp
A[Parent(i)] <= A[i]
```

The smallest value is stored at root of the heap.

## Operations on Min Heap:

1) **getMini()**: It returns the root element of Min Heap. Time Complexity of this operation is **O(1)**.

2) **extractMin()**: Removes the minimum element from MinHeap. Time Complexity of this Operation is **O(Logn)** as this operation needs to maintain the heap property (by calling heapify()) after removing root.

3) **decreaseKey()**: Decreases value of key. The time complexity of this operation is **O(Logn)**. If the decreases key value of a node is greater than the parent of the node, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

4) **insert()**: Inserting a new key takes **O(Logn)** time. We add a new key at the end of the tree. IF new key is greater than its parent, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

5) **delete()**: Deleting a key also takes **O(Logn)** time. We replace the key to be deleted with minum infinite by calling decreaseKey(). After decreaseKey(), the minus infinite value must reach root, so we call extractMin() to remove the key.

## Psuedocode

### Recursive Approach

```cpp
MinHeapify(A, i)
    smallest = i
    l = Left(i)
    r = Right(i)
    if l <= A.heap_size and A[l] < A[i]
        smallest = l
    if r <= A.heap_size and A[r] < A[smallest]
        smallest = r
    if smallest != i
        swap A[i] and A[smallest]
        MinHeapify(A, smallest)
```

### Iterative Approach

```cpp
MinHeapify(A, i)
    while i ≤ A.heap_size:
        smallest = i
        l = Left(i)
        r = Right(i)
        if l ≤ A.heap_size and A[l] > A[i]:
            smallest = l
        if r ≤ A.heap_size and A[r] > A[smallest]:
            smallest = r
        if smallest != i:
            swap A[i] and A[smallest]
             i = smallest
        else break
```

## Usage

- Generally used in priority queues.

