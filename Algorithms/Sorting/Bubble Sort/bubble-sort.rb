=begin
    Bubble Sort
=end

def BubbleSort(arr)
    n = arr.length
    j = 0
    i = 0
    while i < n
        while j < n-i-1
            if arr[j] > arr[j+1]
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
            j += 1
        end
        i += 1
    end
    print arr
end


arr = [3, 1, 5, 8, 11, 10]
BubbleSort(arr)


