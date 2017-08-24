"""
    Heap Sort
"""


def Heapify(l, root, size):
    left = 2 * root + 1
    right = left + 1
    if left < size and l[left] > l[root]:
        largest = left
    else:
        largest = root

    if right < size and l[right] > l[largest]:
        largest = right

    if largest != root:
        l[root], l[largest] = l[largest], l[root]
        Heapify(l, largest, size)


def Heap_Sort(l):
    # Build Heap
    for i in range(int((len(l) - 1) / 2), -1, -1):
        Heapify(l, i, len(l))

    for i in range(len(l) - 1, 0, -1):
        l[0], l[i] = l[i], l[0]
        Heapify(l, 0, i)

    return l

print(Heap_Sort([2, 4, 3, 1, 6, 8, 4]))
