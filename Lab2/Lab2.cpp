#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

/*
 * Lab 2 by Jacob Duncan at Salisbury University for Dr. Joseph Anderson
 * This Lab is a test of QuickSort and MergeSort, almost identical to 
 * Lab 1, however using two different sorts. This lab will test QuickSort and
 * MergeSort with values from 100-100000 and record the number of comparisons
 * the sort made, as well as the time it took for the sort to complete
*/

int long quickComparisons; // global variable / counter for QuickSort comparisons
int long mergeComparisons; // gloval variable / counter for MergeSort comparisons

void resetFiles(){ // function that clears the files in order to write only the current run
  std::ofstream quick;
  quick.open("quick.dat", std::ofstream::out | std::ofstream::trunc);
  quick.close();
  std::ofstream merge;
  merge.open("merge.dat", std::ofstream::out | std::ofstream::trunc);
  merge.close();
}

void swap(int &a, int &b){ // swap function that swaps two elements of an array
    int temp = a;
    a = b;
    b = temp;
}

void genRandomArray(int* arr, int n){ // inserts random numbers into array
    srand(time(NULL));
    for (int i = 0; i < n+1; i++){
        int random = (rand()%n);
        arr[i] = random;
    }
}

void genBackwardsArray(int* arr, int n){ // inserts descended numbers into array
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

void genSortedArray(int* arr, int n){ // inserts ascended numbers into array
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		arr[i] = i;
	}
}

void genDuplicatedElementArray(int* arr, int n){ // inserts duplicated numbers into array
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

int partition(int* arr, int start, int end){ // function that splits the array into two
    int pivot = arr[start];
    int loc = start + 1;
    int swaps = 0;
    for(int i = start + 1; i <= end; i++){
        quickComparisons++;
        if(arr[i] < pivot){
            swap(arr[loc], arr[i]);
            loc++;
        }
    }
    swap(arr[start], arr[loc - 1]);
    return loc - 1;
}

void quickSort(int *arr, int start, int end)
{ // actually does the QuickSort
  int pivot;
  int swaps = 0;
  if (start <= end - 1)
  {
    pivot = partition(arr, start, end); // call partition method on the array and set the return equal to pivot
    quickSort(arr, start, pivot - 1); // calls quicksort once for left side
    quickSort(arr, pivot + 1, end); // calls quicksort once for right side
  }
}

void merge(int *arr, int left, int mid, int right){
  int leftSize = mid - left + 1;
  int rightSize = right - mid;
  int Left[leftSize], Right[rightSize]; // make two new arrays Left and Right
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
      mergeComparisons++;
      arr[k] = Left[i++]; // add that value to the array
    }
    else{
      mergeComparisons++;
      arr[k] = Right[j++]; // else add the right value to the array
    }
  }
  while(i < leftSize){
    arr[k++] = Left[i++]; // increase size as needed
  }
  while(j < rightSize){
    arr[k++] = Right[j++]; // increase size as needed
  }
}

void mergeSort(int *arr, int left, int right){
  int mid;
  if(left < right){
    mid = (left+right)/2; // get "pivot" or mid of array
    mergeSort(arr, left, mid); // call QuickSort on the left
    mergeSort(arr, mid + 1, right); // call QuickSort on the right
    merge(arr, left, mid, right); // merge the two back together
  }
}

void testSort(void(*sort)(int*, int, int), int* arr, int s, int e){ // test sort function that calculates time each sort takes as well as prints out the number of comparisons each sort took.
    std::ofstream qo;
    qo.open("quick.dat", std::ios_base::app);
    std::ofstream mo;
    mo.open("merge.dat", std::ios_base::app);
    auto start = std::chrono::system_clock::now(); // starts time
    sort(arr, s, e);
    auto end = std::chrono::system_clock::now(); // ends time
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(10);
    std::cout << "-> Sort took: " << elapsed_seconds.count() << "s" << std::endl;
    if(sort == quickSort){
      qo << elapsed_seconds.count() << "\n";
      qo.close();
      std::cout << "-> Comparisons: " << quickComparisons << std::endl;
    }
    else if(sort == mergeSort){
      mo << elapsed_seconds.count() << "\n";
      mo.close();
      std::cout << "-> Comparisons: " << mergeComparisons << std::endl;
    }
    quickComparisons = 0; // set the comparisons back to zero
    mergeComparisons = 0;
}

void printArray(int *arr, int end){ // prints the array, not used, just as an aid to make sure it is sorted
    for(int i = 0; i < end; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void isSorted(int* arr, int n){ // function that determines if an array is sorted or not
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
    int *arr = new int[it];
    void(*sort)(int*, int, int);

      for(int i = 0; i < 25; i++){
        if(i < 12){
          sort = quickSort;
          std::ofstream quickOut;
          quickOut.open("quick.dat", std::ios_base::app);
          std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
          std::cout << "~~~QuickSort with " << it << " elements~~~" << std::endl;
          std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
          std::cout << "\n";

          std::cout << "Random Array" << std::endl;
          genRandomArray(arr, it);
          quickOut << "Random Array with " << it << " elements: ";
          quickOut.close();
          testSort(sort, arr, 0, it);
          isSorted(arr, it);
          std::cout << std::endl;

          quickOut.open("quick.dat", std::ios_base::app);
          std::cout << "Already Sorted Array" << std::endl;
          genSortedArray(arr, it);
          quickOut << "Already sorted array with " << it << " elements: ";
          quickOut.close();
          testSort(sort, arr, 0, it);
          isSorted(arr, it);
          std::cout << std::endl;

          quickOut.open("quick.dat", std::ios_base::app);
          std::cout << "Backwards Sorted Array" << std::endl;
          genBackwardsArray(arr, it);
          quickOut << "Backwards Sorted Array with " << it << " elements: ";
          quickOut.close();
          testSort(sort, arr, 0, it);
          isSorted(arr, it);
          std::cout << std::endl;

          quickOut.open("quick.dat", std::ios_base::app);
          std::cout << "Duplicate Element Array" << std::endl;
          genDuplicatedElementArray(arr, it);
          quickOut << "Duplicate Array with " << it << " elements: ";
          quickOut.close();
          testSort(sort, arr, 0, it);
          isSorted(arr, it);
          std::cout << std::endl;
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
      if(i == 12){
        delete[]arr;
        it = 100;
        arr = new int[it];
      }
      if(i > 12 && i <= 25){
        sort = mergeSort;
        std::ofstream mergeOut;
        mergeOut.open("merge.dat", std::ios_base::app);
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "~~~MergeSort with " << it << " elements~~~" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "\n";

        std::cout << "Random Array" << std::endl;
        genRandomArray(arr, it);
        mergeOut << "Random Array with " << it << " elements: ";
        mergeOut.close();
        testSort(sort, arr, 0, it);
        isSorted(arr, it);
        std::cout << std::endl;

        mergeOut.open("merge.dat", std::ios_base::app);
        std::cout << "Already Sorted Array" << std::endl;
        genSortedArray(arr, it);
        mergeOut << "Presorted Array with " << it << " elements: ";
        mergeOut.close();
        testSort(sort, arr, 0, it);
        isSorted(arr, it);
        std::cout << std::endl;

        mergeOut.open("merge.dat", std::ios_base::app);
        std::cout << "Backwards Sorted Array" << std::endl;
        genBackwardsArray(arr, it);
        mergeOut << "Backwards Sorted Array with " << it << " elements: ";
        mergeOut.close();
        testSort(sort, arr, 0, it);
        isSorted(arr, it);
        std::cout << std::endl;

        mergeOut.open("merge.dat", std::ios_base::app);
        std::cout << "Duplicate Element Array" << std::endl;
        genDuplicatedElementArray(arr, it);
        mergeOut << "Duplicate Array with " << it << " elements: ";
        mergeOut.close();
        testSort(sort, arr, 0, it);
        isSorted(arr, it);
        std::cout << std::endl;
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
  }
  delete[] arr;
  return 0;
}
