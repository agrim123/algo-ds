"""
    Merge sort
"""


def merge(l, left, right, mid):
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if l[i] <= l[j]:
            temp[k] = l[i]
            i += 1
        else:
            temp[k] = l[j]
            j += 1

        k += 1

    while i <= mid:
        temp[k] = l[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = l[j]
        j += 1
        k += 1

    while left <= right:
        l[left] = temp[left]
        left += 1


def divide(l, left, right):
    if left < right:
        mid = left + (right - left) / 2;
        mid = int(mid)

        divide(l, left, mid)
        divide(l, mid + 1, right)

        merge(l, left, right, mid)


def Merge_Sort(l):
    global temp
    temp = [0] * len(l)
    divide(l, 0, len(l) - 1)
    del temp

l = [2, 4, 3, 1, 6, 8, 4]

Merge_Sort(l)

print(l)
