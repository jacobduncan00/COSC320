#include <iostream>
#include <math.h>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <fstream>

/*
	* Jacob Duncan Lab 3 for Dr. Joseph Anderson at Salisbury University
	* this lab tests our skills on creating heaps from arrays, building 
	* max heaps from arrays and being able to sort an array in place by 
	* turning it into a heap and using heap sort.
*/

namespace counter{ // instead of using a global variable, which is frowned upon, we can use a namespace instead
	int swaps = 0;
	int comparisons = 0;
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

void resetFile();
void swap(int&, int&); // function that swaps to numbers in an array
int Left(int); // function that returns the left "child" index of a node
int Right(int); // function that returns the right "child" index of a node
void maxHeapify(Heap&, int); // function that will create a valid heap of elements
void buildMaxHeap(Heap&); // function that creates a valid max heap from an array 
void heapSort(Heap&); // function that will sort a heap
void printArr(Heap&); // function that will print the array
void printHeap(Heap&); // function that will print the heap
void printHeap(Heap&, int, int); // function that will print a sub tree of the heap
bool isSorted(Heap&); // function that determines if the array/heap is sorted
void testSort(void(*sort)(Heap&), Heap&); // function that tests the time and swaps of heap sort
int* genArray(int); // function that generates an array of random integers from 0-99
int* genPresortedArray(int); // function that generates a presorted array
int* genBackwardArray(int); // function that generates an array in descending order

int main(){

	resetFile(); // resets the .dat file to be empty each run
	std::ofstream heap; // output stream for the file
	int testSizesLength = 9;
	int testSizes[] = {15, 1000, 10000, 100000, 500000, 1000000, 5000000, 10000000, 25000000}; // different testing sizes for the various array's/heaps
	void(*sort)(Heap&); // out sort parameter for testSort function
	sort = heapSort;
	Heap n(genPresortedArray(testSizes[0]), testSizes[0]); // uses constructor for heap struct to make a new heap of specified size and length
	
	// Testing the print method of printing subtrees of original heap
	
	std::cout << "##########################################" << std::endl;
	std::cout << "Example of Printing Heap:" << std::endl;
	printHeap(n); // call to print the heap only, not the sub tree heap print
	std::cout << std::endl;
	int start, depth;
	std::cout << "Choose a starting node to print from (root being 0): ";
	std::cin >> start;
	std::cout << "Choose the depth of which you want to print: ";
	std::cin >> depth;
	std::cout << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << "Example of printing a subtree of the Heap:" << std::endl;
	printHeap(n, start, depth); // call to print the subtree version of the heap
	std::cout << std::endl;

	// Time / Size testing begins here of various arrays/heaps
	// Random Array 
	std::cout << "##########################################" << std::endl;
	std::cout << "\e[1m Testing Heap Sort with Random Array: \e[0m" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i < testSizesLength; i++){
		heap.open("heap.dat", std::ios_base::app);
		std::cout << "Heap Sorting array with " << testSizes[i] << " elements..." << std::endl;
		heap << "Random Array with " << testSizes[i] << " elements: ";
		heap.close();
		Heap randHeap(genArray(testSizes[i]), testSizes[i]);
		testSort(sort, randHeap);
	}
	heap.open("heap.dat", std::ios_base::app);
	heap << "\n";
	heap.close();
	std::cout << "##########################################" << std::endl;
	std::cout << std::endl;

	// Testing Array/Heap in ascending order "Presorted"

	std::cout << "##########################################" << std::endl;
	std::cout << "\e[1m Testing Heap Sort with PreSorted Array: \e[0m" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i < testSizesLength; i++){
		heap.open("heap.dat", std::ios_base::app);
		std::cout << "Heap Sorting array with " << testSizes[i] << " elements..." << std::endl;
		heap << "PreSorted Array with " << testSizes[i] << " elements: ";
		heap.close();
		Heap presortedHeap(genPresortedArray(testSizes[i]), testSizes[i]);
		testSort(sort, presortedHeap);
	}
	heap.open("heap.dat", std::ios_base::app);
	heap << "\n";
	heap.close();
	std::cout << "##########################################" << std::endl;
	std::cout << std::endl;

	// Testing Array/Heap in descending order "Backwards"

	std::cout << "##########################################" << std::endl;
	std::cout << "\e[1m Testing Heap Sort with Backward Array: \e[0m" << std::endl;
	std::cout << std::endl;
	for(int i = 1; i < testSizesLength; i++){
		heap.open("heap.dat", std::ios_base::app);
		std::cout << "Heap Sorting array with " << testSizes[i] << " elements..." << std::endl;
		heap << "Backward Array with " << testSizes[i] << " elements: ";
		heap.close();
		Heap backwardsHeap(genBackwardArray(testSizes[i]), testSizes[i]);
		testSort(sort, backwardsHeap);
	}
	std::cout << "##########################################" << std::endl;
	return 0;
}

void resetFile(){
	std::ofstream heap;
	heap.open("heap.dat", std::ofstream::out | std::ofstream::trunc);
	heap.close();
}

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}

int Left(int i){
	return (2 * i) + 1;
}

int Right(int i){
	return (2 * i) + 2;
}

void maxHeapify(Heap& A, int i){
	int leftChild = Left(i);
	int rightChild = Right(i);
	int largest = i;
	
	if((leftChild < A.heap_size) && (A.arr[leftChild] > A.arr[largest])){
		counter::comparisons++;
		largest = leftChild;
	}
	if((rightChild < A.heap_size) && (A.arr[rightChild] > A.arr[largest])){
		counter::comparisons++;
		largest = rightChild;
	}
	if(largest != i){
		swap(A.arr[i], A.arr[largest]);
		counter::swaps++;
		maxHeapify(A, largest);
	}
}

void buildMaxHeap(Heap& A){
	A.heap_size = A.length;
	for(int i = A.length - 1; i >= 0; i--){
		maxHeapify(A, i);
	}
}

void heapSort(Heap& A){
	buildMaxHeap(A);
	for(int i = A.length - 1; i > 0; i--){
		swap(A.arr[0], A.arr[i]);
		counter::swaps++;
		A.heap_size--;
		maxHeapify(A, 0);
	}
}

void printArr(Heap& A){ // Not used in my testing, however it does work
	for(int i = A.length - 1; i > 0; i--){
		std::cout << A.arr[i] << " ";
	}
	std::cout << std::endl;
}

void printHeap(Heap& A){ 
	int n = log2(A.length);

	for(int i = 0; i < A.length; i++){
		std::cout << A.arr[i] << " ";
		for(int j = 1; j <= n; j++){
			if( i == (pow(2.0, j) - 2)){
				std::cout << std::endl;
			}
		}
	}
	std::cout << std::endl;
}

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

bool isSorted(Heap& A){ 
	for(int i = 0; i < A.length - 1; i++){
		if(A.arr[i] > A.arr[i+1]){
			return false;
		}
	}
	return true;
}

void testSort(void(*sort)(Heap&), Heap& A){
	std::ofstream heap;
	heap.open("heap.dat", std::ios_base::app);
	typedef std::chrono::high_resolution_clock Clock;
	auto start = std::chrono::system_clock::now(); // starts time
	sort(A);
	auto end = std::chrono::system_clock::now(); // ends time
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::chrono::duration<double>elapsed_seconds = end-start;
	std::cout << "-> # of comparison: " << counter::comparisons << std::endl;
	std::cout << "-> # of swaps: " << counter::swaps<< std::endl;
	counter::swaps = 0; // resets swap counter for next test
	counter::comparisons = 0; // resets comparison counter for next test
	std::cout << std::setprecision(10);
	std::cout << "-> Sort took " << elapsed_seconds.count() << "s" << std::endl;
	heap << elapsed_seconds.count() << "s\n";
	std::cout << std::endl;

	if(isSorted(A)){
		return;
	}
	else{
		std::cout << "ERROR: Sort was not completed correctly!" << std::endl;
		return;
	}
}

int* genArray(int len){
	int* rtn = new int[len];
	for(int i = 0; i < len; i++){
		rtn[i] = (rand()%100);
	}
	return rtn;
}

int* genPresortedArray(int len){
	int* rtn = new int[len];
	for(int i = 0; i < len; i++){
		rtn[i] = i;
	}
	return rtn;
}

int* genBackwardArray(int len){
	int* rtn = new int[len];
	for(int i = len; i >= 0; i--){
		rtn[i] = i;
	}
	return rtn;
}

