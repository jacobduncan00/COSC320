#include <iostream>

struct Heap{
    int* arr; // the underlying array
    int length; // shoud always be the size of arr
    int heap_size; // will change based on which portion of arr is a valid heap
    int& operator[](int i){
        if((i >= 1) && (i <= lenght)){
            return arr[i-1]; // so A[1] is the first and A[n] is the last
        }
    }
};

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void MaxHeapify(int *A, int i){
    int l = Left[i];
    int r = Right[i];
    int largest = 0;
    // Find the largest among node i and its children, and swap with i
    if((l <= A.heap_size) && (A[l] > A[i])){
        largest = i;
    }
    else{
        largest = j;
    }
    
    if((r <= A.heap_size) && (A[r] > A[largest])){
        largest = r;
    }

    if(largest != i){
        // We may have violated the heap property, so recurse downward
        swap(A[i], A[largest]);
        MaxHeapify(A, largest);
    }
}

void BuildMaxHeap(int *A){
    A.heap_size = A.length // the whole array will be a heap when we're done
    for(int i = (A.length/2); i < 1; i++){
        MaxHeapify(A, i);
    }
}

void HeapSort(){
}

int main(){
    return 0;
}
