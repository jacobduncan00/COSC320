# Questions

#### A. 
My approach to the problem was to make a Two Dimensional Array that would act as
my Matrix. Due to the ability to do this in C++, this made the lab much easier.
I could not imagine how I would approach it without doing this method. The only
real issue was making sure that the Matrix would meet the requirements of each
of the operations. These are accounted for in my program by displaying a message
to the user in the terminal and then exiting the program, in which you will have
to go into the source code and change the Matrix to meet the requirements stated
by the message displayed.

#### B. 
As I analyzed the timing for addition and subtraction. I noticed that they
followed an order in which it was around O(n^2) complexity. This is due to the
fact that in order to complete these operations, the functions use two for, each
of which go to the rows, cols being n in this case. As the size of the Matrix
increases, the time does as well. For two n x n Matrices, the timing analyzed in
my program is corresponds to that of it's theoretical time complexity.

#### C.
The arithmetic time complexity of addition and subtraction would be constant
time. This is due to the fact that arithmetic is a single operation per element
that needed to be "changed" or "manipulated" in the Matrix. For multiplication
however, the arithmetic analysis we would have an order n because there are
three for loops, in which one is needed to sum up the rows/cols. This would take
n amount of operations making the arithmetic time complexity of multiplication
of an n x n Matrix n.

#### D.
My code could be improved in many ways. I am sure there are many more efficient
ways of implementing the operations I have done on my Matrices in this program.
I could have made it more efficient where the program can determine if a Matrix
entered into the program, not generated from the program, is already an
Identity, Diagonal, etc. and have that do less operations, resulting in a lower
time / arithmetic complexity. If I were to use Strassens algorithm, I could also
bring the n^3 complexity of Matrix multiplication down to n^2.8.
