--[[
    Bubble Sort
]]--

function bubble_sort(arr)
    for i=1,#arr do
        for j=1,#arr-i do
            if arr[j] > arr[j+1] then
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
        end
    end
end

arr = {1, 4, 2, 5, 1, 9, 0}

print("Before Sorting")
for i = 1, #arr do
  io.write(arr[i], " ")
end
print()

bubble_sort(arr)

print("After Sorting")
for i = 1, #arr do
  io.write(arr[i], " ")
end
print()
