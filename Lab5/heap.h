#ifndef HEAP_H
#define HEAP_H

#include <iostream>

template <class T>
class Heap{
    private:
        struct HeapObj{
            T* data;
            int key;
            HeapObj(){
                key = -1;
            }
            HeapObj(int){
                // TODO
            }  
            HeapObj(T d, int k){
                data = d;
                key = k;
            }
        };

        void increaseKey(Heap A, int i, int k){
            if(k < data[i]){
					std::cout << "New key is smaller than old key!" << std::endl;
					return;
				}

				A[i] = k;

				while(i > 1 && A[i/2] < A[i]){
					HeapObj<T> temp = A.A[i-1];
					A.A[i-1] = A.A[Parent(i)-1];
					A.A[Parent(i)-1] = temp;
					i = Parent(i);
				};
        }


    public:

        T* data;
        int size;
        int arrSize;
        int Left(int);
        int Right(int);
        int Parent(int);
        int swap(int&, int&);

        void heapSort(T*, int);
        void buildHeap(T*, int);
        void heapify(int);
        void increaseSize(int);

        void peek();
        T extractMax();
        void insert(HeapObj<T>);
        void insert();
        void printHeap();
        
        HeapObj<T> operator[](int);
};

#endif
