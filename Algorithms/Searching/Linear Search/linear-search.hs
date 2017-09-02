{-
-- Linear Search
-}

linearSearch :: Eq a => [a] -> a -> Bool

linearSearch [] _ = False

linearSearch (x:xs) y = (x == y) || linearSearch xs y

main = do
  let arr = [2,4,3,1,4]
  print $ linearSearch arr 1
  print $ linearSearch arr 5
