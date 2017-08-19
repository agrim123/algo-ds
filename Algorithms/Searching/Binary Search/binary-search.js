/*
 * Binary Search
 *
*/

function BinarySearch(arr, k) {
    let n = arr.length
    let l = 0
    let r = n-1
    let mid
    while (l <= r) {
        mid = (l + r)>>1
        if (arr[mid] == k)
            return mid
        else if (arr[mid] < k)
            l = mid + 1
        else
            r = mid - 1
    }
    return -1
}

let arr = [3,5,12,56,92,123,156,190,201,222]
console.log(BinarySearch(arr, 12))
