#include <iostream>
#include "heap.h"

int showmenu(){
    int input = 0;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Extract Max" << std::endl;
    std::cout << "3. Print Max" << std::endl;
    std::cout << "4. Print Heap" << std::endl;
    std::cout << "5. Test Heap" << std::endl;
    std::cout << "6. Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter a #: ";
    std::cin >> input;
    return input;
}

template <class T>
bool processInput(int input, Heap<T>* heap){
    bool flag = false;
    if(input >= 1 && input <= 5){
        switch(input){
            case 1:
                heap->insert();
                break;
            case 2:
                heap->extractMax();
                break;
            case 3:
                std::cout << heap->extractMax() << std::endl;
                break;
            case 4:
                heap->printHeap();
                break;
            case 5:
                //testHeap();
                break;
            case 6:
                flag = true;
                break;
        }
    }
    else{
        std::cout << "Please enter a valid choice!" << std::endl;
    }
    return flag;
}


int main(){
    Heap<int>* HeapTemp = new Heap<int>();
    bool flag = false;
    while(!flag){
        int temp = showmenu();
    }
    return 0;
}

