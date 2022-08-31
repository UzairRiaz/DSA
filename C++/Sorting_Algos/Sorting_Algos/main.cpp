#include <iostream>
#include "sortingAlgos.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int arr[] = { 99,2,4,7,1,22,43,1,0,65,34};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr,size);
    return 0;
}
