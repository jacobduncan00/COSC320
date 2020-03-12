# Questions

#### A)
My approach to this problem was to reuse most of my code from Lab2 and Lab3 as well as add a randomized partition and randomized quickSort function that would allow me to measure the timing of these new sorts. The hiring problem was pretty easy as it only relied on a simple shuffle function that would shuffle the indeces, therefore switching the values in an array. 

#### B)
The theoretical time complexity of the hiring problem is (Cn * n) + (Ch * n). Cn is the constant amount of interviews that take place and Ch is the amount of hires made in order to get the best candidate. For randomized quicksort, the time complexity would be O(nlog(n)). With 20 tests for an average I was not able to notice too much of a difference in the timing/complexity however, if there was larger amounts of test runs then you would be able to see this much more clearly. Mergesort however stays true to its previous time complexity as it will always split itself into sub arrays until it reaches the base and then it will rearrange to build the array sorted.

#### C)
Absolute timing scales nicely. The functions would match my assumptions for how they would run with given n input. The hiring problem would most likely represent O(n) and the randomized quicksort would most likely represent O(nlog(n)). However, because of the randomized choice of a pivot in randomized quicksort the number of swaps will be different from that of normal quicksort as the pivot is not always located at the end. However, this gives it a good average time and can even be faster than normal quicksort.

#### D)
The worst case for the hiring problem would be when you have to hire and fire every single candidate before you find the best candidate, meaning your array or candidates come in descending rank order. However, due the shuffle being random, it is very unlikely that such thing will happen and you usually get a decent average case of how many hires you will have to make. For quicksort however, the worst case will be if you swap were to keep the function sorted and it would swap everything to the way it was previously. Ultimately both of these things are unlikely and would take a while to achieve.

#### F) 
I could see the judgement of my shuffle being compared to that of a true random number generator and using my shuffle vs. a random number generator that would act as the indeces of an array and swap with those. I also could have swap two random indeces instead of swapping a random indece with the end of the array.

#### G)
My code could be greatly improved in terms of readability and organization. I feel like this code was all over the place as we were implementing different data structures and sorts.

