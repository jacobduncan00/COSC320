#include "HeapPQ.cpp"
#include <iostream>

// Lab 5 by Jacob Duncan @ Salisbury University
// This Lab displays a templated priority queue in detail
// it tests int, doubles, as well as strings in a series
// of priority queue functions such as enqueue, dequeue,
// peek, increaseSize, increaseKey, etc.

int main(){

    // Int Test

    HeapPQ<int> intPQ;
    std::cout << "\e[1mInt Heap Priority Queue\e[0m" << std::endl;
    std::cout << "Testing Enqueue" << std::endl;
    std::cout << "---------------" << std::endl;
    intPQ.enqueue(50, 90);
    intPQ.enqueue(1, 100);
    intPQ.print();

    std::cout << "Testing Copy Const" << std::endl;
    std::cout << "------------------" << std::endl;
    HeapPQ<int> copyIntPQ(intPQ);
    copyIntPQ.print();

    std::cout << "Testing Overloaded Assignment Operator" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    HeapPQ<int> IntPQAss = copyIntPQ;
    IntPQAss.print();

    std::cout << "Testing Resizing Array by Enqueuing more" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    intPQ.enqueue(3, 19);
    intPQ.enqueue(7, 21);
    intPQ.enqueue(43, 65);
    intPQ.enqueue(91, 44);
    intPQ.enqueue(66, 29);
    intPQ.print();

    std::cout << "Testing Peek" << std::endl;
    std::cout << "------------" << std::endl;
    HeapPQ<int> peekIntPQ;
    peekIntPQ.enqueue(25, 4);
    peekIntPQ.enqueue(50, 50);
    peekIntPQ.enqueue(35, 90);
    std::cout << "Queue used for peek" << std::endl;
    std::cout << "-------------------" << std::endl;
    peekIntPQ.print();
    std::cout << "Peeking the top" << std::endl;
    std::cout << "---------------" << std::endl;
    peekIntPQ.peek();

    std::cout << "Testing Dequeue" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Queue used for dequeue" << std::endl;
    std::cout << "----------------------" << std::endl;
    intPQ.print();
    int rtn = intPQ.dequeue();
    std::cout << "Value returned: " << rtn << std::endl;
    std::cout << "Contents of Queue after dequeue" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    intPQ.print();
    std::cout << "Dequeing more" << std::endl;
    std::cout << "-------------" << std::endl;
    int rtn2 = intPQ.dequeue();
    int rtn3 = intPQ.dequeue();
    int rtn4 = intPQ.dequeue();
    std::cout << "Values returned from dequeing 3x" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << rtn2 << ", " << rtn3 << ", " << rtn4 << std::endl;
    std::cout << "Contents of Queue after dequeue" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    intPQ.dequeue();

    // Double Test

    std::cout << std::endl;
    std::cout << "\e[1mDouble Heap Priority Queue\e[0m" << std::endl;
    HeapPQ<double> dPQ;
    std::cout << "Testing Enqueue" << std::endl;
    std::cout << "---------------" << std::endl;
    dPQ.enqueue(3.14, 45);
    dPQ.enqueue(6.99, 18);
    dPQ.print();

    std::cout << "Testing Copy Const" << std::endl;
    HeapPQ<double> copyDPQ(dPQ);
    copyDPQ.print();

    std::cout << "Testing Overloaded Assignment Operator" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    HeapPQ<double> DPQAss = copyDPQ;
    DPQAss.print();

    std::cout << "Testing Resizing Array by Enqueuing more" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    dPQ.enqueue(3.34, 19);
    dPQ.enqueue(9.343, 21);
    dPQ.enqueue(934.33, 65);
    dPQ.enqueue(534.3, 44);
    dPQ.enqueue(64.4, 29);
    dPQ.print();

    std::cout << "Testing Peek" << std::endl;
    std::cout << "------------" << std::endl;
    HeapPQ<double> peekdPQ;
    peekdPQ.enqueue(19.9, 4);
    peekdPQ.enqueue(55.5, 50);
    peekdPQ.enqueue(29.9, 90);
    std::cout << "Queue used for peek" << std::endl;
    std::cout << "-------------------" << std::endl;
    peekdPQ.print();
    std::cout << "Peeking the top" << std::endl;
    std::cout << "---------------" << std::endl;
    peekdPQ.peek();

    std::cout << "Testing Dequeue" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Queue used for dequeue" << std::endl;
    std::cout << "----------------------" << std::endl;
    dPQ.print();
    double rtn11 = dPQ.dequeue();
    std::cout << "Value returned: " << rtn11 << std::endl;
    std::cout << "Contents of Queue after dequeue" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    dPQ.print();
    std::cout << "Dequeing more" << std::endl;
    std::cout << "-------------" << std::endl;
    double rtn12 = dPQ.dequeue();
    double rtn13 = dPQ.dequeue();
    double rtn14 = dPQ.dequeue();
    std::cout << "Values returned from dequeing 3x" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << rtn12 << ", " << rtn13 << ", " << rtn14 << std::endl;
    std::cout << "Contents of Queue after dequeue" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    dPQ.dequeue();
    
    // String Test

    std::cout << std::endl;
    std::cout << "\e[1mString Heap Priority Queue\e[0m" << std::endl;
    HeapPQ<std::string> sPQ;
    std::cout << "Testing Enqueue" << std::endl;
    std::cout << "---------------" << std::endl;
    sPQ.enqueue("Bob", 45);
    sPQ.enqueue("Kim", 18);
    sPQ.print();

    std::cout << "Testing Copy Const" << std::endl;
    HeapPQ<std::string> copysPQ(sPQ);
    copysPQ.print();

    std::cout << "Testing Overloaded Assignment Operator" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    HeapPQ<std::string> sPQAss = copysPQ;
    sPQAss.print();

    std::cout << "Testing Resizing Array by Enqueuing more" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    sPQ.enqueue("Jacob", 19);
    sPQ.enqueue("Blaine", 21);
    sPQ.enqueue("Justin", 65);
    sPQ.enqueue("Ryan", 44);
    sPQ.enqueue("Flo", 29);
    sPQ.print();

    std::cout << "Testing Peek" << std::endl;
    std::cout << "------------" << std::endl;
    HeapPQ<std::string> peeksPQ;
    peeksPQ.enqueue("Natasha", 4);
    peeksPQ.enqueue("Joe", 50);
    peeksPQ.enqueue("Richard", 90);
    std::cout << "Queue used for peek" << std::endl;
    std::cout << "-------------------" << std::endl;
    peeksPQ.print();
    std::cout << "Peeking the top" << std::endl;
    std::cout << "---------------" << std::endl;
    peeksPQ.peek();

    std::cout << "Testing Dequeue" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Queue used for dequeue" << std::endl;
    std::cout << "----------------------" << std::endl;
    sPQ.print();
    std::string rtn222 = sPQ.dequeue();
    std::cout << "Value returned: " << rtn222 << std::endl;
    std::cout << "Contents of Queue after dequeue" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    sPQ.print();
    std::cout << "Dequeing more" << std::endl;
    std::cout << "-------------" << std::endl;
    std::string rtn22 = sPQ.dequeue();
    std::string rtn23 = sPQ.dequeue();
    std::string rtn24 = sPQ.dequeue();
    std::cout << "Values returned from dequeing 3x" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << rtn22 << ", " << rtn23 << ", " << rtn24 << std::endl;
    std::cout << "Contents of Queue after dequeue" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    sPQ.dequeue();

    return 0;
}
