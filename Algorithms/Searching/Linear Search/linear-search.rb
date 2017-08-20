=begin
    Linear Search
=end

def LinearSearch(arr, k)
    i = 0
    while(i<arr.length)
        if arr[i] == k
           return i
        end
        i += 1
    end
    return -1
end

print LinearSearch([3, 5, 12, 56, 92, 123, 156, 190, 201, 222], 12)
