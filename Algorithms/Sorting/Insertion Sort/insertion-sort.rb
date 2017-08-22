=begin
    Insertion Sort
=end

def InsertionSort(arr)
    n = arr.length
    i = 1
    while i < n
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j]
            arr[j+1] = arr[j]
            j -= 1
        end
        arr[j+1] = key
        i += 1
    end
    print("Insertion Sort")
    print arr
end

InsertionSort([3, 1, 5, 8, 11, 10])
