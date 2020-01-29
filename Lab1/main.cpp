#include <iostream>
#include <stdio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>

void fillArr(int* arr, int n){
    srand(time(NULL));
    for (int i = 0; i < n+1; i++){
        int random = (rand()%9);
        arr[i] = random;
    }
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
}

void selectionSort(int* arr, int n){
    int min, counter = 0;
    for(int i = 0; i <= n-2; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[j+1]){
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
        counter++;
    }   
}

void testSort(void(*sort)(int*, int), int* arr, int n){
    auto start = std::chrono::system_clock::now(); // starts time
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout << "Started at " << std::ctime(&start_time) << std::endl;
    sort(arr, n);
    auto end = std::chrono::system_clock::now(); // ends time
    std::chrono::duration<double>elapsed_seconds = end-start; // gets elapsed time
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
}

void printArr(int* arr, int n){
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

int main(){
    int N = 101;
    int* arr = new int[N];
    fillArr(arr, N);
    printArr(arr, N);
    void (*sort)(int*, int);
    sort = bubbleSort;
    sort(arr, N);

    testSort(bubbleSort, arr, N);
    testSort(selectionSort, arr, N);

    printArr(arr, N);
    return 0;
}