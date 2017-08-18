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


def printArray(arr):
    for i in range(len(arr)):
        print("%d " % arr[i])
    print('\n')


if __name__ == "__main__":
    print("Unsorted Array : ", [3, 1, 5, 8, 11, 10])
    bubbleSort()
