# Interpolation Search

def InterpolationSearch(arr, search_item)
    high = arr.length - 1
    low = 0
    while(low <= high and search_item >= arr[low] and search_item <= arr[high])
        r = high - low
        run = arr[high] - arr[low]
        x = search_item - arr[low]
        pos = low + (r / run) * x

        if arr[pos] == search_item
            return pos
        elsif search_item < arr[pos]
            high = pos - 1
        else
            low = pos + 1
        end
    end
    return -1
end

print(InterpolationSearch([1, 3, 12, 4, 5, 6, 7, 8, 9, 10], 10))
