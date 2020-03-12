 
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <math.h>

void resetFile(){
	std::ofstream timing;
    std::ofstream size;
	timing.open("timing.dat", std::ofstream::out | std::ofstream::trunc);
	timing.close();
    size.open("size.dat", std::ofstream::out | std::ofstream::trunc);
	size.close();
}

struct Heap{
    int* arr;
	int length;
	int heap_size;
	Heap(int* array, int len){ // constructor for a heap
		arr = array; // sets the array of the heap
		length = len; // sets the length of the heap's array
		heap_size = 0; // initializes heap_size to 0
	}
	~Heap(){
		delete[] arr; // deallocates memory by deleting the heap's aray
	}
};

// Function to swap values

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

// Function to shuffle an array 

void shuffle(int* arr, int n){
    for(int i = 0; i < n; i++){
        int j = (rand()%n);
        //std::cout << "Random Number: " << j << std::endl;
        swap(arr[i], arr[j]);
    }
}

// generates array

int* genArray(int len){
	int* rtn = new int[len];
	for(int i = 0; i < len; i++){
		rtn[i] = (rand()%len);
	}
	return rtn;
}

// Gets left child of node in heap

int Left(int i){
	return (2 * i) + 1;
}

// Gets right child of node in heap

int Right(int i){
	return (2 * i) + 2;
}

// maxHeapifies heap

void maxHeapify(Heap& A, int i){
	int leftChild = Left(i);
	int rightChild = Right(i);
	int largest = i;
	
	if((leftChild < A.heap_size) && (A.arr[leftChild] > A.arr[largest])){
		largest = leftChild;
	}
	if((rightChild < A.heap_size) && (A.arr[rightChild] > A.arr[largest])){
		largest = rightChild;
	}
	if(largest != i){
		swap(A.arr[i], A.arr[largest]);
		maxHeapify(A, largest);
	}
}

// builds Max Heap by calling maxHeapify

void buildMaxHeap(Heap& A){
	A.heap_size = A.length;
	for(int i = A.length - 1; i >= 0; i--){
		maxHeapify(A, i);
	}
}

// Sorts a Heap

void heapSort(Heap& A){
	buildMaxHeap(A);
	for(int i = A.length - 1; i > 0; i--){
		swap(A.arr[0], A.arr[i]);
		A.heap_size--;
		maxHeapify(A, 0);
	}
}

// Function to print values in heap, testing purposes

void printHeap(Heap& A, int start, int end){
	if(A.length < 1){
		std::cout << "Heap is empty!" << std::endl;
		return;
	}
	std::cout << A.arr[start] << "\n";
	int startOfRow = (2*start)+1;
	for(int i = 2; i <= end; i++){
		for(int j = startOfRow; j < (startOfRow + pow(2, i-1)); j++){
			if(j < A.length){
				std::cout << A.arr[j] << " ";
			}
			else{
				std::cout << "*" << " ";
			}
		}
		std::cout << std::endl;
		startOfRow = (2*startOfRow)+1;
	}
}

// function that determines if an array is sorted or not

void isSortedArr(int* arr, int n){ 
	if (n == 0){
		std::cout << "ERROR: Array has no contents" << std::endl;
		return;
	}
	if (n == 1){
		std::cout << "-> Array is Sorted" << std::endl;
		return;
	}
	for(int i = 1; i < n; i++){
		if(arr[i-1] > arr[i]){
			std::cout << "-> Array is NOT Sorted" << std::endl;
			return;
		}
	}
	std::cout << "-> Array is Sorted" << std::endl;
	return;
}

// function that determines if a Heap is sorted or not

bool isSortedHeap(Heap& A){ 
	for(int i = 0; i < A.length - 1; i++){
		if(A.arr[i] > A.arr[i+1]){
			return false;
		}
	}
	return true;
}

// hire assistant function simulates the hiring process when an array
// is given in random "shuffled" order. How many average hires are made is
// calculated

int hireAssistant(int* rank, int n){
    int hires = 1;
    int curr = rank[0];
    for(int i = 1; i < n; i++){
        if(rank[i] > curr){
            //std::cout << "Current: " << curr << std::endl;
            //std::cout << "Rank[i]: " << rank[i] << std::endl;
            curr = rank[i];
            hires++;
        }
    }
    std::cout << "Hires with " << n << " candidates: " << hires << std::endl;
    return hires;
}

// Partition used by quicksort

int partition(int* arr, int start, int end){
    int a = start;
    int b = end;
    for(int i = start; i < end; i++){
        if(arr[i] < arr[b]){
            swap(arr[i], arr[a]);
            a++;
        }
    }
    swap(arr[b], arr[a]);
    return a;
}

// Sorts array using quickSort

void quickSort(int* arr, int start, int end){
    if(start < end){
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

// partition function that chooses a pivot at random

int randomPartition(int* arr, int start, int end){
    int swaps;
    int n = (rand());
    int random = start + n % (end-start + 1);
    swap(arr[end], arr[random]);
    swaps++;
    return partition(arr, start, end);
}

// quickSort that calls randomPartition 

void randomQuickSort(int* arr, int start, int end){
    if(start < end){
        int pivot = randomPartition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

// used by mergeSort to divide array into sub arrays and merge back to form sorted array

void merge(int *arr, int left, int mid, int right){
  int leftSize = mid - left + 1;
  int rightSize = right - mid;
  int *Left = new int[leftSize];
  int *Right = new int[rightSize]; // make two new arrays Left and Right
  int i, j, k;
  for(i = 0; i < leftSize; i++){
    Left[i] = arr[left + i]; // creates index's for the Left array
  }
  for(j = 0; j < rightSize; j++){
    Right[j] = arr[mid+j+1]; // creates index's for the Right array
  }
  i=0, j=0;
  for(k = left; (i < leftSize) && (j < rightSize); k++){
    if(Left[i] < Right[j]){ // if the left is less than the right
      arr[k] = Left[i++]; // add that value to the array
    }
    else{
      arr[k] = Right[j++]; // else add the right value to the array
    }
  }
  while(i < leftSize){
    arr[k++] = Left[i++]; // increase size as needed
  }
  while(j < rightSize){
    arr[k++] = Right[j++]; // increase size as needed
  }
  delete[] Left;
  delete[] Right;
}

// sorts an array by dividing down and rebuilding into sorted array

void mergeSort(int *arr, int left, int right){
  int mid;
  if(left < right){
    mid = (left+right)/2; // get "pivot" or mid of array
    mergeSort(arr, left, mid); // call QuickSort on the left
    mergeSort(arr, mid + 1, right); // call QuickSort on the right merge(arr, left, mid, right); // merge the two back together
    merge(arr, left, mid, right);
   } 
}

// function that calls a sort given a function

void testSort(void(*sort)(int*, int, int), int* arr, int s, int e){
    sort(arr, s, e);
    if(sort == quickSort){
        std::cout << "QuickSort with " << e << " elements" << std::endl;
    }
    else if(sort == mergeSort){
        std::cout << "MergeSort with " << e << " elements" << std::endl;
    }
    else if(sort == randomQuickSort){
        std::cout << "Random QuickSort with " << e << " elements" << std::endl;
    }
}

// function that calls the heapSort, only takes in heaps

void testHeapSort(void(*sort)(Heap&), Heap& A){
	sort(A);
	if(isSortedHeap(A)){
        std::cout << "-> Heap is Sorted" << std::endl;
		return;
	}
	else{
		std::cout << "ERROR: Sort was not completed correctly!" << std::endl;
        std::cout << std::endl;
		return;
	}
}

int main(){
    resetFile(); // resets the .dat file to be empty each run
	std::ofstream timing; // output stream for the file
    std::ofstream size;
    srand(time(NULL));

    // Hiring Problem
    std::cout << std::endl;
    int star = 1000;
    int cand = 10000;
    int sum = 0;
    for (int i = star; i <= cand; i += 1000){
        for(int l = 0; l < 10; l++){
            int *arr2 = new int[i];
            for(int j = 0; j < i; j++){
              arr2[j] = j;
            }
            shuffle(arr2, i);
            sum += hireAssistant(arr2, i);
            delete[] arr2;
        }
    }

    int denom = cand/star*10;
    int sumFinal = sum/denom;
    std::cout << std::endl;
    std::cout << "\e[1mAverage Hires: \e[0m" << sumFinal << std::endl;
    std::cout << std::endl;

    // Sorting Testing
    int sizes[18] = {10000, 60000, 210000, 260000, 310000, 360000, 410000, 460000, 510000, 560000, 610000, 660000, 710000, 760000, 810000, 860000, 910000, 960000};
    bool flag = false;
    timing.open("timing.dat", std::ios_base::app);
    timing << "quick sort" << "\n";
    timing.close();
    for(int i = 0; i < 18; i++){
        for(int l = 0; l < 20; l++){
            int* tempArr = genArray(sizes[i]);
            typedef std::chrono::high_resolution_clock Clock;
            auto start = std::chrono::system_clock::now(); // starts time
            shuffle(tempArr, sizes[i]);
            testSort(quickSort, tempArr, 0, sizes[i]- 1);
            isSortedArr(tempArr, sizes[i]);
            auto end = std::chrono::system_clock::now(); // ends time
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::chrono::duration<double>elapsed_seconds = end-start;
            std::cout << std::setprecision(10);
            std::cout << "-> Sort took " << elapsed_seconds.count() << std::endl;
            size.open("size.dat", std::ios_base::app);
            size << sizes[i] << "\n";
            size.close();
            timing.open("timing.dat", std::ios_base::app);
            timing << elapsed_seconds.count() << "\n";
            timing.close();
            std::cout << std::endl;
            delete[] tempArr;
        }
    }
    timing.open("timing.dat", std::ios_base::app);
    timing << "\n" << "random quick sort" << "\n";
    timing.close();

    for(int i = 0; i < 18; i++){
        for(int l = 0; l < 20; l++){
            int* tempArr = genArray(sizes[i]);
            typedef std::chrono::high_resolution_clock Clock;
            auto start = std::chrono::system_clock::now(); // starts time
            shuffle(tempArr, sizes[i]);
            testSort(randomQuickSort, tempArr, 0, sizes[i]- 1);
            isSortedArr(tempArr, sizes[i]);
            auto end = std::chrono::system_clock::now(); // ends time
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::chrono::duration<double>elapsed_seconds = end-start;
            std::cout << std::setprecision(10);
            std::cout << "-> Sort took " << elapsed_seconds.count() << std::endl;
            std::cout << std::endl;
            size.open("size.dat", std::ios_base::app);
            size << sizes[i] << "\n";
            size.close();
            timing.open("timing.dat", std::ios_base::app);
            timing << elapsed_seconds.count() << "\n";
            timing.close();
            delete[] tempArr;
        }
    }

    timing.open("timing.dat", std::ios_base::app);
    timing << "\n" << "mergesort" << "\n";
    timing.close();

    for(int i = 0; i < 18; i++){
        for(int l = 0; l < 20; l++){
            int* tempArr = genArray(sizes[i]);
            typedef std::chrono::high_resolution_clock Clock;
            auto start = std::chrono::system_clock::now(); // starts time
            shuffle(tempArr, sizes[i]);
            testSort(mergeSort, tempArr, 0, sizes[i]-1);
            isSortedArr(tempArr, sizes[i]);
            auto end = std::chrono::system_clock::now(); // ends time
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::chrono::duration<double>elapsed_seconds = end-start;
            std::cout << std::setprecision(10);
            std::cout << "-> Sort took " << elapsed_seconds.count() << std::endl;
            std::cout << std::endl;
            size.open("size.dat", std::ios_base::app);
            size << sizes[i] << "\n";
            size.close();
            timing.open("timing.dat", std::ios_base::app);
            timing << elapsed_seconds.count() << "\n";
            timing.close();
            delete[] tempArr;
        }
    }

    timing.open("timing.dat", std::ios_base::app);
    timing << "\n" << "heap sort" << "\n";
    timing.close();

    for(int i = 0; i < 18; i++){
        for(int l = 0; l < 20; l++){
            int* tempArr = genArray(sizes[i]);
            typedef std::chrono::high_resolution_clock Clock;
            auto start = std::chrono::system_clock::now(); // starts time
            shuffle(tempArr, sizes[i]);
            Heap test(tempArr, sizes[i]);
            std::cout << "HeapSort with " << sizes[i] << " elements" << std::endl;
            testHeapSort(heapSort, test);
            auto end = std::chrono::system_clock::now(); // ends time
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::chrono::duration<double>elapsed_seconds = end-start;
            std::cout << std::setprecision(10);
            std::cout << "-> Sort took " << elapsed_seconds.count() << std::endl;
            std::cout << std::endl;
            size.open("size.dat", std::ios_base::app);
            size << sizes[i] << "\n";
            size.close();
            timing.open("timing.dat", std::ios_base::app);
            timing << elapsed_seconds.count() << "\n";
            timing.close();
        }
    }
    return 0;
}