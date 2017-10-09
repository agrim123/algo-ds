{-
    Quick Sort
-}

quickSort :: (Ord a) => [a] -> [a]

quickSort [] = []

quickSort (x:xs) =
    let smaller = quickSort [a | a <- xs, a <= x]
        bigger = quickSort [a | a <- xs, a > x]
    in  smaller ++ [x] ++ bigger

main = do
    print $ quickSort [2,4,1,2,7,4,56,2,4,5,7]
    print $ quickSort "Some Awesome Sentence!"
