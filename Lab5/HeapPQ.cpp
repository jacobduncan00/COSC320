#include "HeapPQ.h"
#include <iostream>

template <class T>
void HeapPQ<T>::increaseKey(int i, int k){ // increases the priority of a HeapObj
    if(arr[i].key > k){
        throw "This is an INCREASE key function...";
    }
    arr[i].key = k;
    while(i != 0 && arr[i].key > arr[i/2].key){
        swap(arr[i], arr[i/2]);
        i /= 2; // i = i/2;
    }
}

template <class T>
void HeapPQ<T>::increaseSize(){
    HeapObj<T>* newArray = new HeapObj<T>[arrLen * 2]; // makes new array twice the size of the previous
    for(int i = 0; i < arrLen; i++){
        newArray[i] = arr[i];
    }
    delete[] arr;
    arr = newArray;
    arrLen *= 2;
}

template <class T>
HeapPQ<T>::HeapPQ(){ // creates the priority queue
    arr = new HeapObj<T>[3];
    arrLen = 3;
    heap_size = -1;
}

template <class T>
HeapPQ<T>::HeapPQ(const HeapPQ<T>& r){ // copies a HeapPQ into another HeapPQ
    arr = new HeapObj<T>[r.arrLen];
    if(r.heap_size != -1){
        for(int i = 0; i <= r.heap_size; i++){
            arr[i] = r.arr[i];
        }
    }
    arrLen = r.arrLen;
    heap_size = r.heap_size;
}

template <class T>
HeapPQ<T>::~HeapPQ(){ // deletes the dynamically allocated array
    delete[] arr;
}

template <class T>
HeapPQ<T>& HeapPQ<T>::operator=(const HeapPQ<T>& r){ // assignment operator of one priority queue to another
    if(this == &r){ // if the one being compared is already the same
        return *this;
    }
    delete[] arr;
    arr = new HeapObj<T>[r.arrLen];
    if(r.heap_size != -1){
        for(int i = 0; i <= r.heap_size; i++){
            arr[i] = r.arr[i];
        }
    }
    arrLen = r.arrLen;
    heap_size = r.heap_size;
    return *this;
}

template <class T>
T HeapPQ<T>::dequeue(){ // used to dequeue the front data in the queue and return it
    if(heap_size == -1){ // if queue is empty throw
        throw "The queue is empty...";
    }
    HeapObj<T> rtn = arr[0];
    arr[0] = arr[heap_size];
    heap_size--;
    maxHeapify(0);
    return rtn.data;
}

template <class T>
void HeapPQ<T>::maxHeapify(int i){ // fixes the violations made if swapped
    int Left = (2*i)+1;
    int Right = (2*i)+2;
    int max = i;
    if(Left <= heap_size && arr[Left].key > arr[i].key){
        max = Left;
    }
    if(Right <= heap_size && arr[Right].key > arr[max].key){
        max = Right;
    }
    if(max != i){
        swap(arr[i], arr[max]);
        maxHeapify(max);
    }
}

template <class T>
void HeapPQ<T>::swap(HeapObj<T>& a, HeapObj<T>& b){ // swaps values in the priority queue
    HeapObj<T> temp = a;
    a = b;
    b = temp;
}

template <class T>
void HeapPQ<T>::peek(){ // prints the data and key of the object in the front of the queue
    if(heap_size == -1){
        throw "The queue is empty...";
    }
    std::cout << "HeapObj dequeued..." << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Data: " << arr[0].data << std::endl;
    std::cout << "Key: " << arr[0].key << std::endl;
    std::cout << "-------------------" << std::endl;
}

template <class T>
void HeapPQ<T>::enqueue(T d, int k){ // inserts or enqueues a HeapObj into the queue with a certain key or priority
    if(k < 0){
        throw "Not a valid key";
    }
    HeapObj<T> in(d, 0);
    if(heap_size + 1 == arrLen){
        increaseSize();
    }
    arr[++heap_size] = in;
    increaseKey(heap_size, k);
}

template <class T>
void HeapPQ<T>::print(){
    if(heap_size == -1){
        std::cout << "Queue is empty...";
        return;
    }
    std::cout << std::endl;
    std::cout << "-> Front <-" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i <= heap_size; i++){
        std::cout << "-------------------" << std::endl;
        std::cout << "Data: " << arr[i].data << std::endl;
        std::cout << "Key: " << arr[i].key << std::endl;
        std::cout << "-------------------" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "-> Back <-" << std::endl;
    std::cout << std::endl;
}





