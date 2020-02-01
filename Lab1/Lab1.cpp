#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

void resetFiles(){
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

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void genRandomArray(int* arr, int n){
    srand(time(NULL));
    for (int i = 0; i < n+1; i++){
        int random = (rand()%n);
        arr[i] = random;
    }
}

void genBackwardsArray(int* arr, int n){
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

void genSortedArray(int* arr, int n){
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		arr[i] = i;
	}
}

void genDuplicatedElementArray(int* arr, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        if(i < n/25){
            arr[i] = (rand()%10);
        }
        else if (i > n/25 && i < n/50){
        }
    }
            arr[i] = (rand()%5);
        }
        else{
            arr[i] = (rand()%3);
}

void bubbleSort(int* arr, int n){
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

void insertionSort(int* arr, int n){
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

void selectionSort(int* arr, int n){
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

void testSort(void(*sort)(int*, int), int* arr, int n){
    std::ofstream bubbleOut;
    bubbleOut.open("bubble.dat", std::ios_base::app);
    std::ofstream insertionOut;
    insertionOut.open("insertion.dat", std::ios_base::app);
    std::ofstream selectionOut;
    selectionOut.open("selection.dat", std::ios_base::app);
    auto start = std::chrono::system_clock::now(); // starts time
    sort(arr, n);
    auto end = std::chrono::system_clock::now(); // ends time
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(8);
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

int main(){ // Make files for each sort and copy paste that to microsoft excel
    resetFiles();
    int it = 100;
    int* arr = new int[it];
    void(*sort)(int*, int);
    for(int i = 0; i < 13; i++){
        if (i < 4){
            sort = bubbleSort;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "~~~Bubble Sort with " << it << " elements~~~" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;
            std::cout << "Random Array" << std::endl;
            genRandomArray(arr, it);
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);

            std::cout << "Already Sorted Array" << std::endl;
            genSortedArray(arr, it);
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);

            std::cout << "Backwards Sorted Array" << std::endl;
            genBackwardsArray(arr, it);
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);

            std::cout << "Duplicate Element Array" << std::endl;
            genDuplicatedElementArray(arr, it);
            testSort(bubbleSort, arr, it);
            isSorted(arr, it);
            delete[] arr;
            it *= 10;
            arr = new int[it];
        }
        if (i == 4){
            delete[] arr;
            it = 100;
            arr = new int[it];
        }
        if (i > 4 && i <= 8){
            sort = insertionSort;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "~~~Insertion Sort with " << it << " elements~~~" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;
            std::cout << "Random Array" << std::endl;
            genRandomArray(arr, it);
            testSort(insertionSort, arr, it);
            isSorted(arr, it);

            std::cout << "Already Sorted Array" << std::endl;
            genSortedArray(arr, it);
            testSort(insertionSort, arr, it);
            isSorted(arr, it);

            std::cout << "Backwards Sorted Array" << std::endl;
            genBackwardsArray(arr, it);
            testSort(insertionSort, arr, it);
            isSorted(arr, it);

            std::cout << "Duplicate Element Array" << std::endl;
            genDuplicatedElementArray(arr, it);
            testSort(insertionSort, arr, it);
            isSorted(arr, it);
            delete[] arr;
            it *= 10;
            arr = new int[it];
        }
        if (i == 8){
            delete[] arr;
            it = 100;
            arr = new int[it];
        }
        if(i > 8 && i <= 13){
            sort = selectionSort;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "~~~Selection Sort with " << it << " elements~~~" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << std::endl;
            std::cout << "Random Array" << std::endl;
            genRandomArray(arr, it);
            testSort(selectionSort, arr, it);
            isSorted(arr, it);

            std::cout << "Already Sorted Array" << std::endl;
            genSortedArray(arr, it);
            testSort(selectionSort, arr, it);
            isSorted(arr, it);

            std::cout << "Backwards Sorted Array" << std::endl;
            genBackwardsArray(arr, it);
            testSort(selectionSort, arr, it);
            isSorted(arr, it);

            std::cout << "Duplicate Element Array" << std::endl;
            genDuplicatedElementArray(arr, it);
            testSort(selectionSort, arr, it);
            isSorted(arr, it);
            delete[] arr;
            it *= 10;
            arr = new int[it];
        }
    }
    delete[] arr;
    return 0;
}
