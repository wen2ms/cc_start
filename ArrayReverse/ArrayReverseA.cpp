#include <iostream>

#define N 5

template <class BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last) {
    while (first != last && first != --last) {
        auto temp = *last;
        *last = *first;
        *first = temp;

        first ++;
    }
}


int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int reverse_arr[N];

    std::cout << "--------------------------\n";
    std::cout << "I generated a reverse array.\n";

    for (int i = 0; i < N; i ++) 
        reverse_arr[i] = arr[i];

    int n = sizeof(reverse_arr) / sizeof(reverse_arr[0]);
    reverse(reverse_arr, reverse_arr + n);

    for (int i = 0; i < N; i ++) 
        std::cout << reverse_arr[i] << ' ';

    std::cout << "\n--------------------------\n";


    return 0;
}