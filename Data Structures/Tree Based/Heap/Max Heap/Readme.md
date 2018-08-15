# Max Heap

> Where the value of the root node is greater than or equal to either of its children.

```cpp
A[Parent(i)] >= A[i]
```

The largest value is stored at root of the heap.

## Psuedocode

### Recursive Approach

```cpp
MaxHeapify(A, i)
    largest = i
    l = Left(i)
    r = Right(i)
    if l <= A.heap_size and A[l] >= A[i]
        largest = l
    if r <= A.heap_size and A[r] > A[largest]
        largest = r
    if largest != i
        swap A[i] and A[largest]
        MaxHeapify(A, largest)
```

### Iterative Approach

```cpp
MaxHeapify(A, i)
    while i ≤ A.heap_size:
        largest = i
        l = Left(i)
        r = Right(i)
        if l ≤ A.heap_size and A[l] > A[i]:
            largest = l
        if r ≤ A.heap_size and A[r] > A[largest]:
            largest = r
        if largest != i:
            swap A[i] and A[largest]
             i = largest
        else break
```

## Usage

- Used in heapsort.

[Code](/Algorithms/Sorting/Heap%20Sort/heap-sort.cpp)

