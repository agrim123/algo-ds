"""
  Linear Search
"""


def LinearSearch(arr, k):
    for i in range(0, len(arr)):
        if(arr[i] == k):
            return i
    return -1


print(LinearSearch([3, 5, 12, 56, 92, 123, 156, 190, 201, 222], 12))
