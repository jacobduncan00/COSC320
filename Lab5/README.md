<strong>type "make" then "./main.exe" :)</strong>

# Questions

#### A)
My approach to this problem was to used a priority queue heap. This can be done if you already have a grasp on what a queue and heap are.
There are minor differences in the functionality of queues and priority queues when using enqueue and dequeue functions. The heap is 
essential to this problem as you can use maxHeapify to fix any problems in the array when you are using the dequeue function. The increaseKey
function is also essential in making a priority queue, this ensures you place the object in the correct place in the queue. 

#### B)
Dequeue : O(log(n)) due to maxHeapify
Enqueue : Worse Case O(log(n)) if enqueue in front of array with highest priority
Print   : O(n) loops through whole array 
Peek    : O(1) constant time because it simply analyzes only the first element

#### C)
The timing scales evenly with a positive correlation. The enqueue and dequeue functions will be efficient because they are O(log(n)) however
if you were to ever put an extremely large priority queue then the print function would take a long time as it is O(n).

#### D)
Pathfinding Algorithms! Djikstras Algorithm uses a weighted graph, in this case priority queues would be extremely useful.
Priority Queues would also would be good on high traffic websites such as seatgeek when new tickets drop for concerts or something like that, if you
try to enter the website after a lot of other people do, then you will be placed in a priority queue based on the time you entered the website.

#### E)
I think this code, as it is, is not very useful in large scale projects. We would need to implement more funcitonality to the priority queue to make this a 
functional, realisitic application. However, for simple use such as this lab, it is a great way to understand how they work. The queue is made very simple
and even making a GUI for something like this wouldnt be too hard and allow the user to play around with the keys and changing positions in the array.
