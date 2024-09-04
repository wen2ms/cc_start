#include <iostream>
#include <cstdlib>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide an array of integers as command-line arguments.\n";
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i ++)
        arr[i] = std::atoi(argv[i + 1]);

    std::cout << "------------------------------\n";
    std::cout << "I generated bubble sort.\n";

    bubbleSort(arr, n);

    std::cout << "Sort array: ";
    for (int i = 0; i < n; i ++) 
        std::cout << arr[i] << ' ';

    std::cout << "\n------------------------------\n";

    return 0;
}