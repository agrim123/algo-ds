/*
 * Merge sort
 *
*/


function Merge(arr, left, right, middle){
    let n1 = middle - left + 1,
        n2 = right - middle,
        L = [],
        R = []

    for(let i =0;i<n1;i++)
        L[i] = arr[left + i]

    for(let j=0;j<n2;j++)
        R[j]=arr[middle+j+1]

    i = 0
    j = 0
    let k = left
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]
            i++
        } else {
            arr[k] = R[j]
            j++
        }
        k++
    }

    while (i < n1) {
        arr[k] = L[i]
        i++
        k++
    }

   while (j < n2) {
        arr[k] = R[j]
        j++
        k++
    }
}

function MergeSort(arr, left, right) {
    if(left < right) {
        let middle = Math.floor((left +right)/2)

        MergeSort(arr, left, middle)
        MergeSort(arr, middle+1, right)
        Merge(arr, left, right, middle)
    }
}


arr = [1,3,6,54,56,78,78,6754,643,5,4]
MergeSort(arr, 0, arr.length-1)
console.log(arr)
