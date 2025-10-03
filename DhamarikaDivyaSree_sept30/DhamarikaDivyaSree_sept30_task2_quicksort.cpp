#include "quicksort.h"
#include <iostream>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // First element as pivot
    int left = low;
    int right = high;

    while (left < right) {
        // Move right pointer left until a smaller element than pivot is found
        while (left < right && arr[right] >= pivot)
            right--;

        if (left < right) {
            arr[left] = arr[right];
            left++;
        }

        // Move left pointer right until a greater element than pivot is found
        while (left < right && arr[left] <= pivot)
            left++;

        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }

    // Place pivot in its correct position
    arr[left] = pivot;
    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
