#ifndef HeapPQ_H
#define HeapPQ_H

#include <iostream>

template <class T>
struct HeapObj{
    T data;
    int key;

    HeapObj(){
        data = {}; // default constructor has empty array
        key = 0; // default constructor sets key to 0
    }

    HeapObj(T d, int k){
        data = d;
        key = k;
    }  

    HeapObj<T>& operator=(const HeapObj<T>& r){
        if(this == &r){ // checks to see if lhs == rhs
            return *this;
        }
        data = r.data;
        key = r.key;
        return *this; // returns HeapObj with r attributes
    }

    HeapObj(const HeapObj<T>& r){
        data = r.data;
        key = r.key;
    }
};

template <class T>
class HeapPQ{

    private:

        HeapObj<T>* arr;
        int arrLen;
        int heap_size;
        void increaseKey(int, int);
        void increaseSize();
        void swap(HeapObj<T>&, HeapObj<T>&);


    public:

        HeapPQ();
        HeapPQ(const HeapPQ<T>&);
        HeapPQ<T>& operator=(const HeapPQ<T>&);
        ~HeapPQ();
        void enqueue(T, int);
        T dequeue();
        void peek();
        void print();
        void maxHeapify(int);
        
};

#endif
