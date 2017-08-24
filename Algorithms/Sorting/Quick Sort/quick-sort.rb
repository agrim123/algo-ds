=begin
    Quick Sort
=end


def partition(arr, low, high)
    i = low-1
    pivot = arr[high]
    j = low
    while(j<high)
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        end
         j += 1
    end

    arr[i+1], arr[high] = arr[high], arr[i+1]

    return i+1
end


def QuickSort(arr, low, high)
    if low < high
        pi = partition(arr, low, high)
        QuickSort(arr, low, pi-1)
        QuickSort(arr, pi+1, high)
    end
end


arr = [10, 7, 8, 9, 1, 5, 1]
QuickSort(arr, 0, arr.length-1)
print arr
