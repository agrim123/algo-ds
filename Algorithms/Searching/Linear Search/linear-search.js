/*
 * Linear Search
 *
 */

function LinearSearch(arr, k) {
    for(let i =0; i< arr.length;i++){
        if (arr[i] == k) {
            return i
        }
    }
    return -1
}

console.log(LinearSearch([3, 5, 12, 56, 92, 123, 156, 190, 201, 222], 12))
