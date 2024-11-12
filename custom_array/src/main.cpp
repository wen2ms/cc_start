#include <iostream>
#include "card_box.hpp"

template <class Card>
void test_push_back(CardBox<Card>& box) {
    std::cout << "box: ";
    for (int i = 0; i < 5; i++) {
        box.push_back(i);
        std::cout << box[i] << ' '; 
    }
    std::cout << '\n';
}

template <class Card>
void test_copy(const CardBox<Card>& box) {
    CardBox<Card> box_copy(5);
    std::cout << "The size of box_copy's elements: " << box_copy.get_cards_number() << '\n';
    box_copy = box;
    box_copy[0] = 1;
    std::cout << "The size of box_copy's elements: " << box_copy.get_cards_number() << '\n';

    std::cout << "box_copy: ";
    for (int i = 0; i < 5; i++) {
        std::cout << box_copy[i] << ' '; 
    }
    std::cout << '\n';

    std::cout << "box: ";
    for (int i = 0; i < 5; i++) {
        std::cout << box[i] << ' '; 
    }
    std::cout << '\n';
}

template <class Card>
void test_remove(CardBox<Card>& box) {
    box.remove();

    int cards_number = box.get_cards_number();
    std::cout << "The size of box's elements: " << cards_number << '\n';

    for (int i = 0; i < cards_number; i++) {
        box.remove();
    }
    box.remove();  // test index out of range.
}

int main() {
    CardBox<int> box(5);

    test_push_back(box);

    test_copy(box);

    test_remove(box);

    return 0;
}