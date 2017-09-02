{-
-- Binary Search
-}

binarySearch :: [Int] -> Int -> Int -> Int -> Int

binarySearch xs val low high
    | high < low = -1
    | xs!!mid < val = binarySearch xs val (mid+1) high
    | xs!!mid > val = binarySearch xs val low (mid-1)
    | otherwise = mid
    where
        mid = (low + high) `div` 2

main = do
    let arr = [3,5,12,56,92,123,156,190,201,222]
    print $ binarySearch arr 12 0 ((length arr) - 1)

