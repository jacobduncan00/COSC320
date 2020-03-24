# Questions

#### 2b)
The hash function used in this program can take a large 'pool' of numbers (2^64) for most systems, and allow you to extract a subsection of that pool. However, the final hash is calculated by allowing the subsection to be mapped to a value in the larger area and therefore giving you the 'multiplication method'.

#### a)
My approach to this problem was to research hashes and find out as much about them as I could before I tried to tackle the lab because before this lab I knew nothing about hashing. After looking up some basic hash functions and realizing how hashing worked in C++, it was easy for me to wrap my head around the concept and implement it into my lab.

#### b)
The first string hashing function I used, I think is a pretty common one, but basically I extracted each character of the string and casted it to an integer and proceeded to sum those values. When returning I modded that sum by the table size or the 'pool' size. The second function I used to hash strings was once again summing the individual characters of the string and then adding them to an odd number which. There are many different ways you can hash strings and numbers I have found out.

#### c)
My code is terrible and I am very new to hashing and I am still learning the fundamental concepts. I know there are much better ways to perform hashing and more efficient algorithms that will produce a better hash, however I am still trying to learn about those and will hopefully be able to implement those into project 2 when that time comes.
