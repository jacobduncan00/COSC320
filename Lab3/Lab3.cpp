#include<iostream>
#include<stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <iomanip>

using namespace std;

struct Heap {
		int* arr; // the underlying array
		int length; // should always be the size of arr int 
		int heap_size; // will change based on which portion of arr is a valid heap
		int& operator[](int i){
			// good idea to also check that 1 <= i <= length;
            //if(i >= 1 && i <= length){
				return arr[i-1]; 
            //}
			// so A[1] is the first and A[n] is the last

		};
};

void swap(int &val1, int &val2){
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

void maxheapify(Heap A, int i){
	int l = 2*i-1;
	int r = 2*i;
	int max;

	if(l <= A.heap_size && A[l] > A[i]){
		max = l;
	}
	else{
		max = i;
	}
	if(r <= A.heap_size && A[r] > A[max]){
		max = r;
	}
	if(max != i){
		swap(A[i], A[max]);
		maxheapify(A, max);
	}
}

void buildmaxheap(Heap A){
	A.heap_size = A.length;
	for(int i = (A.length/2); i >= 1; i--){
		maxheapify(A, i);
	}
}

void heapSort(Heap A){
	cout << endl;
	cout << "Starting Heap Sort...";
	buildmaxheap(A);
	for(int i = A.length; i >= 2; i--){
		swap(A[1], A[i]); 
		A.heap_size = A.heap_size - 1; 
		maxheapify(A, 1); 
	}
    std::cout << "sort complete!" << std::endl;
};

void testSort(void(*sort)(Heap), Heap a){ // test sort function opens all files and calculates time taken by sort, exporting to file and terminal
    typedef std::chrono::high_resolution_clock Clock;
    auto start = std::chrono::system_clock::now(); // starts time
    sort(a);
    auto end = std::chrono::system_clock::now(); // ends time
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(10);
    std::cout << "-> Sort took " << elapsed_seconds.count() << "s" << std::endl;
}

void printHeap(Heap A, int a){
	int n = 10;

	for(int i = 1; i < a; i++){
		cout << A[i] << " ";
		for(int j = 1; j <= n; j++){
			if( i == (pow(2.0, j) - 1)){
				cout << endl;
			}
		}
	}
	cout << endl;
};

int main(){
    int x;
    std::cout << "How many elements do you want in your Heap? ";
    std::cin >> x;

	int start = 0;
	int end = x;

	Heap Trial;

	Trial.arr = new int[x];
    srand(time(NULL));
	for(int i = 1; i <= x; i++){
      int j = rand()%100;
      Trial[i] = j;
      cout << " | " << Trial[i] << " | ";
    };

	Trial.length = x;
    void(*sort)(Heap);
    sort = heapSort;
    testSort(sort, Trial);
    
	printHeap(Trial, x);
};
