def selection_sort():
    arr = [3, 1, 5, 8, 11, 10]
    for i in range(len(arr)):
        m = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[m]:
                m = j
            arr[m], arr[i] = arr[i], arr[m]
    print("Selection Sort")
    printArray(arr)


def bubbleSort():
    arr = [3, 1, 5, 8, 11, 10]
    n = len(arr)

    for i in range(n):

        # Last i elements are already in place
        for j in range(0, n-i-1):

            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print("Bubble Sort")
    printArray(arr)


def insertionSort():
    arr = [3, 1, 5, 8, 11, 10]
    for i in range(1, len(arr)):

        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j]:
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = key
    print("Insertion Sort")
    printArray(arr)


def printArray(arr):
    for i in range(len(arr)):
        print("%d " % arr[i])
    print('\n')


if __name__ == "__main__":
    print("Unsorted Array : ", [3, 1, 5, 8, 11, 10])
    selection_sort()
    bubbleSort()
    insertionSort()
