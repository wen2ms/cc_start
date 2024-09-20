#include <iostream>

#define N 4

int main(void) {
    int arr[] = {1, 2, 3, 4};
    int reverse_arr[N];

    std::cout << "--------------------------\n";
    std::cout << "I generated a reverse array.\n";

    for (int i = 0; i < N/2; i ++) {
        reverse_arr[i] = arr[N - i - 1];
        reverse_arr[N - i - 1] = arr[i];
    }
    if (N%2 == 1)
        reverse_arr[N/2] = arr[N/2];

    for (int i = 0; i < N; i++) 
        std::cout << reverse_arr[i] << ' ';

    std::cout << "\n--------------------------\n";


    return 0;
}