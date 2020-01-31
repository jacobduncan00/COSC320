(a) What is the theoretical time complexity of your sorting algorithms (best and worst case), in terms
of the array size?

                   Best Case         Worst Case 

Bubble Sort:         Ω(n)              O(n^2)
Insertion Sort:      Ω(n)              O(n^2)
Selection Sort:      Ω(n^2)            O(n^2)


(b) How does the absolute timing scale with the number of elements in the array? The size of the
elements? Can you use the data collected to rectify this with the theoretical time complexity?

Positive correlation between size of array and time took to complete sort. As n increases with the size of the elements,
so does the time it takes to sort. Yes, you can most certainly use your information given from the timings of each sort,
along with your knowledge of the size of elements in each array and you can validate the Best and Worst cases of each.

(c) Aggregate your data into a graph of the complexity for the various array sizes, for example with
a spreadsheet program like LibreOffice Calc or Microsoft Word.

See attached images.

(d) How do the algorithms perform in different cases? What is the best and worst case, according to
your own test results?

As the amount of elements in each array increases so does the time it takes to complete the sort. Also, by implementing
the backward sorted array we can verify the Worst case for these algorithms as a backward sorted array would be the worst
case for most.

In my tests, the Best and Worst case of each algorithm ties in very close to the theoretical time complexity of the sorting
algorithms.

(e) How could the code be improved in terms of usability, efficiency, and robustness?

After testing these three sorting algorithms and comparing them to other sorting algorithms that I know, I would suggest
to use Merge sort as it is a superior sort.
