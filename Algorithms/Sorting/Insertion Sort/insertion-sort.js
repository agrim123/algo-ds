/*
 * Insertion Sort
 *
 */

function InsertionSort(arr) {
    for (let i = 1; i < arr.length; ++i) {
        let key = arr[i]
        let j = i-1
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]
            j--
        }
        arr[j+1] = key
    }
    return arr
}

console.log(InsertionSort([3,1,5,2,75,7,4,12,35,54,1,256,24,5736453,1,7]))
