#include "heap.h"
#include <cmath>

template <class T>
HeapObj<T>::HeapObj(){
    key = -1;
}

template <class T>
HeapObj<T>::HeapObj(T d, int k){
    data = d;
    key = k;
}

template <class T>
HeapObj<T>::HeapObj(int in){

}

template <class T>
Heap<T>::Heap(int s){
    arrSize =  s;
    size = 0;
    data = new HeapObj<T>[arrSize];
}

template <class T>
void Heap<T>::heapSort(T* inArr, int size){
    buildHeap(inArr, size);
    for(int i = 0; i < size; i++){
        inArr[i] = extractMax();
    }
}

template <class T>
HeapObj<T> Heap<T>::operator[](int i){
    return data[i];
}

template <class T>
void Heap<T>::insert(){
    std::cout << "Size: " << size << " heap_size: " << arrSize << std::endl;
    HeapObj<T> n = HeapObj<T>(1);
    std::cout << "Enter priority: ";
    std::cin >> n.key; 
    insert(n);
}

template <class T>
void Heap<T>::insert(HeapObj<T> newNode){
    increaseSize(size+1);
    int i = size;
    while(i > 0 && data[Parent(i)].key < newNode.key){
        data[i] = data[parent(i)];
        i = Parent(i);
    }
    data[i] = newNode;
    size++;
}

template <class T>
void Heap<T>::peek(){
    std::cout << "Max: " << data[0].data;
}

template <class T>
T Heap<T>::extractMax(){
    if(size < 1){
        throw "Error: Heap Underflow";
    }
    else{
        T max = data[0].data;
        data[0] = data[size - 1];
        size--;
        heapify(0);
        return max;
    }
}

template <class T>
void Heap<T>::buildHeap(T* A, int s){
    size = s;
    arrSize = size+1;
    for(int i = (size/2)-1; i >= 0; i--){
        heapify(i);
    }
}

template <class T>
void Heap<T>::heapify(int i){
    int L = Left(i);
    int R = Right(i);
    int max = i;
    if(i >= size){
        return 0;
    }
    if(L < size && data[i].key < data[L].key){
        max = L;
    }
    else{
        max = i;
    }
    if(R < size && data[max].key < data[R].key){
        max = R:
    }
    if(max != i){
        swap(i, max);
        heapify(max);
    }
}

template <class T>
void Heap<T>::increaseSize(int paraSize){
    int newSize = 2;
    while(paraSize > newSize){
        newSize *= 2;
    }
    if(newSize > arrSize){
        std::cout << "Increasing size to " << newSize << std::endl;
        HeapObj<T>* newData = new HeapObj<T>[newSize];
        int i;
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        size = paraSize;
        arrSize = newSize;

        HeapObj<T>* temp = data;
        data = newData;
        newData = temp;
        delete newData;
    }
}

template <class T>
int Heap<T>::Left(int i){
    return (2*i)+1;
}

template <class T>
int Heap<T>::Right(int i){
    return (2*i)+2;
}

template <class T>
int Heap<T>::Parent(int i){
    if(i % 2 == 0){
        return (i-1)/2;
    }
    else{
        return i/2;
    }
}

template <class T>
void Heap<T>::swap(int& a, int &b){
    HeapObj<T> temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void Heap<T>::printHeap(){
    int nextLine = 2;
    int offSet = 2;
    for(int i = 0; i < size; i++){
        if(i+1 == nextLine){
            std::cout << std::endl;
            nextLine *= 2;
        }
        if(data[i].key != -1){
            std::cout << data[i].ley << ": " << data[i].data;
        }
        else{
            std::cout << " * * * ";
        }

        for(int j = 0; j < offSet; j++){
            std::cout << " ";
        }
    }
    std::cout << std::endl << std::endl;
}
