#include <iostream>

template <class T>
void select_sort(T* arr, int num) {
    for (int i = 0; i < num; i++) {
        int min_index = i;
        for (int j = i + 1; j < num; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        T temp;
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main(int argv, char* argc[]) {
    std::cout << "I generated an example of select sort with template\n";
    std::cout << "----------------------\n";

    if (argv < 2) {
        std::cout << "Please provide an array as the command-line arguments\n";
        return 1;
    }

    int n = argv - 1;
    int arr[n];

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = std::atoi(argc[i + 1]);

        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    select_sort(arr, n);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "----------------------\n";

    return 0;
}