#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

void resetFiles(){ // function that clears the files in order to write only the current run
  std::ofstream bubble;
  bubble.open("bubble.dat", std::ofstream::out | std::ofstream::trunc);
  bubble.close();
  std::ofstream insertion;
  insertion.open("insertion.dat", std::ofstream::out | std::ofstream::trunc);
  insertion.close();
  std::ofstream selection;
  selection.open("selection.dat", std::ofstream::out | std::ofstream::trunc);
  selection.close();
}

void swap(int &a, int &b){ // function that swaps two elements in an array
    int temp = a;
    a = b;
    b = temp;
}

void genRandomArray(int* arr, int n){ // function fills an array with random numbers
    srand(time(NULL));
    for (int i = 0; i < n+1; i++){
        int random = (rand()%n);
        arr[i] = random;
    }
}

void genBackwardsArray(int* arr, int n){ // function that fills an array with numbers in descending order
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		arr[i] = (rand()%n);
	}
	int flag = 1;
	int temp;
	for(int j = 0; (j <= n) && flag; j++){
		flag = 0;
		for (int k = 0; k < n-1; k++){
			if(arr[k+1] > arr[k]){
				swap(arr[k+1], arr[k]);
				flag = 1;
			}
		}
	}
}

void genSortedArray(int* arr, int n){ // functon that fills an array with numbers in ascending order
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		arr[i] = i;
	}
}

void genDuplicatedElementArray(int* arr, int n){ // function that fills an array with duplicated numbers
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        if(i < n/25){
            arr[i] = (rand()%10);
        }
        else if (i > n/25 && i < n/50){
            arr[i] = (rand()%5);
        }
        else{
            arr[i] = (rand()%3);
        }
	}
}

void bubbleSort(int* arr, int n){ // bubble sort, plain and trash
    if(n == 0){
        std::cout << "Cannot Bubble Sort an empty array!" << std::endl;
        return;
    }
    bool swapped = true;
    double counter = 0;
    while(swapped){
        for(int i = 0; i < n-1; i++){
            swapped = false;
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    counter++;
                    swapped = true;
                }
            }
            if (swapped == false){
                break;
            }
        }
    }
    std::cout << "-> Swaps: " << counter << std::endl;
}

void insertionSort(int* arr, int n){ // insertion sort, plain and decent
    if(n == 0){
        std::cout << "Cannot Insertion Sort an empty array!" << std::endl;
        return;
    }
    int temp, j;
    double counter = 0;
    for(int i = 0; i < n; i++){
      temp = arr[i];
      j = i - 1;
      while(j >= 0 && arr[j] > temp){
       arr[j+1] = arr[j];
       j = j - 1;
       counter++;
   }
   arr[j+1] = temp;
}
std::cout << "-> Swaps: " << counter << std::endl;
}

void selectionSort(int* arr, int n){ // selection sort, almost as bad as bubble
    if(n == 0){
        std::cout << "Cannot Selection Sort an empty array!" << std::endl;
        return;
    }
    int min = 0;
    double counter = 0;
    for(int i = 0; i <= n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
        counter++;
    }
    std::cout << "-> Swaps: " << counter << std::endl;
}

void testSort(void(*sort)(int*, int), int* arr, int n){ // test sort function opens all files and calculates time taken by sort, exporting to file and terminal
    std::ofstream bubbleOut;
    bubbleOut.open("bubble.dat", std::ios_base::app);
    std::ofstream insertionOut;
    insertionOut.open("insertion.dat", std::ios_base::app);
    std::ofstream selectionOut;
    selectionOut.open("selection.dat", std::ios_base::app);
    typedef std::chrono::high_resolution_clock Clock;
    auto start = std::chrono::system_clock::now(); // starts time
    sort(arr, n);
    auto end = std::chrono::system_clock::now(); // ends time
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(10);
    std::cout << "-> Sort took " << elapsed_seconds.count() << "s" << std::endl;
    if(sort == bubbleSort){
        bubbleOut << elapsed_seconds.count() << "\n";
        bubbleOut.close();
    }
    else if(sort == insertionSort){
        insertionOut << elapsed_seconds.count() << "\n";
        insertionOut.close();
    }
    else if(sort == selectionSort){
        selectionOut << elapsed_seconds.count() << "\n";
        selectionOut.close();
    }
}

void printArray(int* arr, int n){ // prints array, for testing purposes only, not required
    for(int i = 0; i < n; i++){
        if (i % 10 == 0 && i != 0){
            std::cout << arr[i] << std::endl;
        }
        else if (i % 10 != 0){
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\n";
}

void isSorted(int* arr, int n){ // fhecks to see if the array is sorted or not
	if (n == 0){
		std::cout << "ERROR: Array has no contents" << std::endl;
		std::cout << std::endl;
		return;
	}
	if (n == 1){
		std::cout << "-> Array is Sorted" << std::endl;
		std::cout << std::endl;
		return;
	}
	for(int i = 1; i < n; i++){
		if(arr[i-1] > arr[i]){
			std::cout << "-> Array is NOT Sorted" << std::endl;
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "-> Array is Sorted" << std::endl;
	std::cout << std::endl;
	return;
}

int main(){
    resetFiles();
    int it = 100;
    int* arr = new int[it];
    void(*sort)(int*, int);
    for(int i = 0; i < 32; i++){
        if (i < 7){ // runs bubble sort from 100-50000
            sort = bubbleSort;
            std::ofstream bubbleOut;
            bubbleOut.open("bubble.dat", std::ios_base::app);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "~~~Bubble Sort with " << it << " elements~~~" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;
            std::cout << "Random Array" << std::endl;
            genRandomArray(arr, it);
            bubbleOut << "Random Array with " << it << " elements: ";
            bubbleOut.close();
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);

            bubbleOut.open("bubble.dat", std::ios_base::app);
            std::cout << "Already Sorted Array" << std::endl;
            genSortedArray(arr, it);
            bubbleOut << "PreSorted Array with " << it << " elements: ";
            bubbleOut.close();
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);

            bubbleOut.open("bubble.dat", std::ios_base::app);
            std::cout << "Backwards Sorted Array" << std::endl;
            genBackwardsArray(arr, it);
            bubbleOut << "Backward Array with " << it << " elements: ";
            bubbleOut.close();
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);

            bubbleOut.open("bubble.dat", std::ios_base::app);
            std::cout << "Duplicate Element Array" << std::endl;
            genDuplicatedElementArray(arr, it);
            bubbleOut << "Duplicate Array with " << it << " elements: ";
            bubbleOut.close();
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);
            delete[] arr;
            if(it >= 10000){
                it += 10000;
            }
            else{
                it *= 10;
            }
            arr = new int[it];
        }
        if (i == 7){ // resets array size to 100 elements
            delete[] arr;
            it = 100;
            arr = new int[it];
        }
        if (i > 7 && i <= 19){ // runs insertion sort from 100-100000 elements
            sort = insertionSort;
            std::ofstream insertionOut;
            insertionOut.open("insertion.dat", std::ios_base::app);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "~~~Insertion Sort with " << it << " elements~~~" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;
            std::cout << "Random Array" << std::endl;
            genRandomArray(arr, it);
            insertionOut << "Random Array with " << it << " elements: ";
            insertionOut.close();
            testSort(insertionSort, arr, it);
            isSorted(arr, it);

            insertionOut.open("insertion.dat", std::ios_base::app);
            std::cout << "Already Sorted Array" << std::endl;
            genSortedArray(arr, it);
            insertionOut << "PreSorted Array with " << it << " elements: ";
            insertionOut.close();
            testSort(insertionSort, arr, it);
            isSorted(arr, it);

            insertionOut.open("insertion.dat", std::ios_base::app);
            std::cout << "Backwards Sorted Array" << std::endl;
            genBackwardsArray(arr, it);
            insertionOut << "Backward Array with " << it << " elements: ";
            insertionOut.close();
            testSort(insertionSort, arr, it);
            isSorted(arr, it);

            insertionOut.open("insertion.dat", std::ios_base::app);
            std::cout << "Duplicate Element Array" << std::endl;
            genDuplicatedElementArray(arr, it);
            insertionOut << "Duplicate Array with " << it << " elements: ";
            insertionOut.close();
            testSort(insertionSort, arr, it);
            isSorted(arr, it);
            delete[] arr;
            if(it >= 10000){
                it += 10000;
            }
            else{
                it *= 10;
            }
            arr = new int[it];
        }
        if (i == 19){ // resets array size to 100 elements
            delete[] arr;
            it = 100;
            arr = new int[it];
        }
        if(i > 19 && i <= 32){ // runs selection sort from 100-100000 elements
            sort = selectionSort;
            std::ofstream selectionOut;
            selectionOut.open("selection.dat", std::ios_base::app);
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "~~~Selection Sort with " << it << " elements~~~" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;
            std::cout << "Random Array" << std::endl;
            genRandomArray(arr, it);
            selectionOut << "Random Array with " << it << " elements: ";
            selectionOut.close();
            testSort(selectionSort, arr, it);
            isSorted(arr, it);

            selectionOut.open("selection.dat", std::ios_base::app);
            std::cout << "Already Sorted Array" << std::endl;
            genSortedArray(arr, it);
            selectionOut << "PreSorted Array with " << it << " elements: ";
            selectionOut.close();
            testSort(selectionSort, arr, it);
            isSorted(arr, it);

            selectionOut.open("selection.dat", std::ios_base::app);
            std::cout << "Backwards Sorted Array" << std::endl;
            genBackwardsArray(arr, it);
            selectionOut << "Backwards Array with " << it << " elements: ";
            selectionOut.close();
            testSort(selectionSort, arr, it);
            isSorted(arr, it);

            selectionOut.open("selection.dat", std::ios_base::app);
            std::cout << "Duplicate Element Array" << std::endl;
            genDuplicatedElementArray(arr, it);
            selectionOut << "Duplicate Array with " << it << " elements: ";
            selectionOut.close();
            testSort(selectionSort, arr, it);
            isSorted(arr, it);
            delete[] arr;
            if(it >= 10000){
                it += 10000;
            }
            else{
                it *= 10;
            }
            arr = new int[it];
        }
    }
    delete[] arr;
    return 0;
}
