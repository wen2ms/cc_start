#include <iostream>

template<class ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last) {
    if (first ==last) return first;

    ForwardIterator largest = first;

    first ++;
    for (; first != last; first ++) {
        if (*largest < *first)
            largest = first;
    } 

    return largest;
}

int main(void) {
    std::cout << "------------------------------\n";
    std::cout << "I generated the maximum element in array.\n";

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The maximum element is: " << *max_element(arr, arr + n) << '\n';
    std::cout << "------------------------------\n";


    return 0;
}
