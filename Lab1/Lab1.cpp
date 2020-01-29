#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void fillArray(int* arr, int n){
    srand(time(NULL));
    for (int i = 0; i < n+1; i++){
        int random = (rand()%9);
        arr[i] = random;
    }
}

int* genBackwardsArray(int n){
	srand(time(NULL));
	int* rtn = new int[n];
	for(int i = 0; i < n; i++){
		rtn[i] = (rand()%9);
	}
	int flag = 1;
	int temp;
	for(int j = 0; (j <= n) && flag; j++){
		flag = 0;
		for (int k = 0; k < n-1; k++){
			if(rtn[k+1] > rtn[k]){
				temp = rtn[k];	
				rtn[k] = rtn[k+1];
				rtn[k+1] = temp;
				flag = 1;
			}
		}
	}
	return rtn;
}

int* genSortedArray(int n){
	srand(time(NULL));
	int* rtn = new int[n];
	for(int i = 0; i < n; i++){
		rtn[i] = i;
	}
	return rtn;
}

void bubbleSort(int* arr, int n){
    bool swapped = true;
    int counter = 0;
    while(swapped){
        for(int i = 0; i < n-1; i++){
            swapped = false;
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr[j+1]){
                    std::swap(arr[j], arr[j+1]);
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

void insertionSort(int* arr, int n){
	int temp, j;
	int counter = 0;
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

void selectionSort(int* arr, int n){
    int min, counter = 0;
    for(int i = 0; i <= n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
        counter++;
    } 
    std::cout << "-> Swaps: " << counter << std::endl; 
}

void testSort(void(*sort)(int*, int), int* arr, int n){ // TODO - Figure out timing
    auto start = std::chrono::system_clock::now(); // starts time
    sort(arr, n);
    auto end = std::chrono::system_clock::now(); // ends time
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(8);
    std::cout << std::setw(18) << "-> Sort took " << elapsed_seconds.count() << " s" << std::endl;
}

void printArray(int* arr, int n){
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

void isSorted(int* arr, int n){
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
	std::cout << "ms = microseconds" << std::endl;
	std::cout << std::endl;
    int N = 101;
    int* arr = new int[N];
    std::cout << "Bubble Sort" << std::endl;
    fillArray(arr, N);
    void (*sort)(int*, int);
    sort = bubbleSort;
    testSort(bubbleSort, arr, N);
    isSorted(arr, N);

    std::cout << "Insertion Sort" << std::endl;
    fillArray(arr, N);
    void(*sort1)(int*, int);
    sort1 = insertionSort;
    testSort(insertionSort, arr, N);
    isSorted(arr, N);

    std::cout << "Selection Sort" << std::endl;
    fillArray(arr, N);
    void (*sort2)(int*, int);
    sort2 = selectionSort;
    testSort(selectionSort, arr, N);
    isSorted(arr, N);
    return 0;
}