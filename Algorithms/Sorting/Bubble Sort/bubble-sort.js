/*
 * Bubble Sort
 *
 */

function BubbleSort(arr) {
    for (let i = 0; i < arr.length; ++i)
        for (let j = 0; j < arr.length-i-1; ++j)
            if (arr[j] > arr[j+1])
                arr[j+1] = [arr[j], arr[j] = arr[j+1]][0]
    return arr
}

console.log(BubbleSort([3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7]))
