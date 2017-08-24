=begin
    Selection Sort
=end


def SelectionSort(arr)
    i = 0
    while(i < arr.length)
        m = i
        j = i + 1
        while(j < arr.length)
            if arr[j] < arr[m]
                m = j
            end
            arr[m], arr[i] = arr[i], arr[m]
            j += 1
        end
        i += 1
    end
    arr
end


print SelectionSort([3, 1, 5, 8, 1, 11, 10])
