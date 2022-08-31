#include <iostream>
#include "sortingAlgos.hpp"

using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
    
    printArr(arr, n);
}

void selectionSort(int arr[], int n){
    int min_idx;
    min_idx = 0;
    for(int i = 0; i < n; i++){
        min_idx = i;
        for(int j = i; j < n;j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
    
    printArr(arr, n);
}
