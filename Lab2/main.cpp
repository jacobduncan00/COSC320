#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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
            arr[i] = (rand()%5);
        }
        else{
            arr[i] = (rand()%3);
        }
	}
}

int partition(int* arr, int start, int end){
    int pivot = arr[start];
    int loc = start + 1;
    int swaps = 0;
    for(int i = start + 1; i <= end; i++){
        if(arr[i] < pivot){
            swap(arr[loc], arr[i]);
            loc++;
            swaps++;
        }
    }
    swap(arr[start], arr[loc - 1]);
    std::cout << "-> Swaps " << swaps << std::endl;
    return loc - 1;
}

void quickSort(int *arr, int start, int end)
{
  int pivot;
  int swaps = 0;
  if (start <= end - 1)
  {
    pivot = partition(arr, start, end); // call partition method on the array and set the return equal to pivot
    quickSort(arr, start, pivot - 1); // calls quicksort once for left side
    quickSort(arr, pivot + 1, end); // calls quicksort once for right side
  }
}

void testSort(void(*sort)(int*, int, int), int* arr, int s, int e){
    auto start = std::chrono::system_clock::now(); // starts time
    sort(arr, s, e);
    auto end = std::chrono::system_clock::now(); // ends time
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(10);
    std::cout << "-> Sort took " << elapsed_seconds.count() << "s" << std::endl;
}

void printArray(int *arr, int end){
    for(int i = 0; i < end; i++){
        std::cout << arr[i] << " ";
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
    int it = 100;
    int *arr = new int[it];
    void(*sort)(int*, int, int);
    sort = quickSort;

    std::cout << "===================" << std::endl;
    std::cout << " Partition Testing " << std::endl;
    std::cout << "===================" << std::endl;
    int array[] = {4, 9, 8, 2, 3};
    printArray(array, 5);
    int p = partition(array, 0, 5);
    std::cout << "Pivot Location: " << p << std::endl;
    std::cout << "Pivot Value: " << array[p] << std::endl;
    printArray(array, 5);


    for(int i = 0; it <= 1000000; i++){
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "~~~QuickSort with " << it << " elements~~~" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "\n";
        std::cout << "Random Array" << std::endl;
        genRandomArray(arr, it);
        testSort(sort, arr, 0, it);
        isSorted(arr, it);
        delete[] arr;
        if(it >= 10000 && it < 100000){
            it += 10000;
        }
        else if(it >= 100000){
            it += 100000;
        }
        else{
           it *= 10;
        }
        arr = new int[it];
    }
    return 0;
}