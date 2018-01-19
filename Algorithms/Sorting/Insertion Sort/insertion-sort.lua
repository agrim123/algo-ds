--[[
    Insertion Sort
--]]

function insertion_sort(arr)
    for i=2,#arr do
        key = arr[i]
        j = i-1
        while j >= 0 and arr[j] > key do
            arr[j+1] = arr[j]
            j = j - 1
        end
        arr[j+1] = key
    end
end

arr = {1, 4, 2, 5, 1, 4}

print("Before Sorting")
for i = 1, #arr do
  io.write(arr[i], " ")
end
print()

insertion_sort(arr)

print("After Sorting")
for i = 1, #arr do
  io.write(arr[i], " ")
end
print()
