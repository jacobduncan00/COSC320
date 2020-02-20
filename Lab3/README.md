# Lab 3 

## Questions:

##### (a) Summarize your approach to the problem, and how your code addresses the abstractions needed.

This lab was a pain to be very honest. I think my main problem was trying to understand the indexing of a heap and how we should be doing it. Although you recommended to use the overloaded operator that will decrease the actual index that we give it by 1, I decided not to use that as it was more complicated than it was helpful when trying to debug my code. However, besides the indexing issues and my sort not working half the time, after about 2 days I was successfully able to sort using heap sort. Printing the sub-tree also proved to be a challenge.

##### (b) What is the theoretical time complexity of your sorting algorithm (best and worst case), in terms of the array size?

Heap Sort  ---  Best Case: Θ(nlog(n)) --- Worst Case: Θ(nlog(n))

##### (c) Test your sorting algorithm on different size and types of arrays, as you did with labs 1 and 2. Be sure to vary the parameters enough to use the observations to answer the next questions!

Completed in the program.

##### (d)  How does the absolute timing scale with the number of elements in the array? The size of the elements? Use the data collected to rectify this with the theoretical time complexity, e.g. what non-asymptotic function of n mostly closely matches the timings that you observe as n grows?

The timing does not change much at all, this sort is extremely fast and cannot compare to even quick sort and merge sort. Only when you start getting to arrays over the size of 10 million will you start putting on some serious time to your sort but besides that, this sort is still incredibly fast. 

The non-asymptotic function that my represents is linear
y = n.

##### (e) Aggregate your data into a graph of the complexity for the various array sizes, for example with a spreadsheet program like LibreOffice Calc or Microsoft Word.

See attached image.

##### (f) How does the sort perform in different cases? What is the best and worst case, according to your own test results?

Heap Sort  ---  Best Case: Θ(nlog(n)) --- Worst Case: Θ(nlog(n))

##### (g) How could the code be improved in terms of usability, efficiency, and robustness?

This code, in my opinion could not be done much more efficiently besides trying to implement the decreasing index overloaded operator for ease of use, however heap sort alone is one of the most efficient and robust sorting algorithms.