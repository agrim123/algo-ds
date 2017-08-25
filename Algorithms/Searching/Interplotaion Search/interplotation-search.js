/*
 * Interpolation Search
 *
 */

function Interpolation_Search(arr, k) {
    let low = 0,
        high = arr.length - 1,
        pos

    while (low <= high && k >= arr[low] && k <= arr[high]) {
        let r = high - low
        let run = arr[high] - arr[low]
        let x = k - arr[low]

        pos = low + Math.floor(r / run) * x

        if (arr[pos] === k)
            return pos
        else if (k < arr[pos])
            high = pos - 1
        else if (k > arr[pos])
            low = pos + 1
    }

    return -1
}

let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

console.log(Interpolation_Search(arr, 5))
