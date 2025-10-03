#include "quicksort.h"
#include <iostream>

int main() {
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array:" << std::endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "\nSorted array:" << std::endl;
    printArray(arr, n);

    return 0;
}
