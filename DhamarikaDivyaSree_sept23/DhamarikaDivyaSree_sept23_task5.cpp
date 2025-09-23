#include <iostream>

// to print the array after every pass
void printArray(int arr[], int size, int pass) {
    std::cout << "After pass " << pass << ": ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
// bucket sort 
void bucketSort(int arr[], int size) {
    const int BUCKETS = 10;
    int bucket[BUCKETS][size];      // 2D bucket array
    int count[BUCKETS];             // Count of elements in each bucket

    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    int place = 1;  // Current digit place
    int pass = 1;// step counter

    while (maxVal / place > 0) {
        // Clear bucket counts 
        for (int i = 0; i < BUCKETS; i++) {
            count[i] = 0;
        }

        // put elements into buckets based on current digit
        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / place) % 10;
            bucket[digit][count[digit]++] = arr[i];
        }

        // copy back to original array
        int index = 0;
        for (int r = 0; r < BUCKETS; r++) {
            for (int j = 0; j < count[r]; j++) {
                arr[index++] = bucket[r][j];
            }
        }

        printArray(arr, size, pass);

        place *= 10;// move to next digit
        pass++;
    }
}

int main() {
    int size;
    std::cout<<"Enter the number of elements:";// to mention the size of array
    std::cin>>size;
    int* arr= new int[size];
    
    std::cout<<"Enter"<<size<<"Positive Intergers Only:\n";// to provide the integers 
    for(int i=0;i<size;i++){
        std::cin>>arr[i];
    }
    std::cout << "Original array: ";// first prints the original array given by the user
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";

    bucketSort(arr, size);

    std::cout << "\nSorted array: "; // prints the sorted array after sorting
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
