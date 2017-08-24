"""
    Selection Sort
"""


def SelectionSort():
    arr = [3, 1, 5, 8, 11, 10]
    for i in range(len(arr)):
        m = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[m]:
                m = j
            arr[m], arr[i] = arr[i], arr[m]
    print("Selection Sort")
    printArray(arr)


def printArray(arr):
    for i in range(len(arr)):
        print("%d " % arr[i])
    print('\n')


if __name__ == "__main__":
    print("Unsorted Array : ", [3, 1, 5, 8, 11, 10])
    SelectionSort()
