#ifndef CARD_BOX_HPP
#define CARD_BOX_HPP

#include <stdexcept>

template <class Card>
class CardBox {
  public:
    CardBox(int storage);

    CardBox(const CardBox& box);

    ~CardBox();

    Card& operator[](int index) const;

    CardBox<Card>& operator=(const CardBox<Card>& box);

    bool push_back(const Card& card);

    bool remove();

    int get_storage() const;
    int get_cards_number() const;

  private:
    Card* first_;
    int storage_;
    int cards_number_;
};

template <class Card>
CardBox<Card>::CardBox(int storage) : storage_(storage), cards_number_(0), first_(new Card[storage]) {}

template <class Card>
CardBox<Card>::CardBox(const CardBox& box) : storage_(box.storage_), cards_number_(box.cards_number_), first_(new Card[box.storage_]) {
    for (int i = 0; i < box.cards_number_; i++) {
        first_[i] = box.first_[i];
    }
}

template <class Card>
CardBox<Card>::~CardBox() {
    delete[] first_;
    first_ = nullptr;
}

template <class Card>
Card& CardBox<Card>::operator[](int index) const {
    if (index >= cards_number_) {
        throw std::out_of_range("Index out of range");
    }

    return first_[index];
}

template <class Card>
CardBox<Card>& CardBox<Card>::operator=(const CardBox<Card>& box) {
    if (this == &box) {
        return *this;
    }

    delete[] first_;

    storage_ = box.storage_;
    cards_number_ = box.cards_number_;

    first_ = new Card[storage_];
    for (int i = 0; i < cards_number_; i++) {
        first_[i] = box.first_[i];
    }

    return *this;
}

template <class Card>
bool CardBox<Card>::push_back(const Card& card) {
    if (cards_number_ == storage_) {
        throw std::out_of_range("Index out of range");
    }

    first_[cards_number_++] = card;
    return true;
}

template <class Card>
bool CardBox<Card>::remove() {
    if (cards_number_ == 0) {
        throw std::out_of_range("Index out of range");
    }

    --cards_number_;
    return true;
}

template <class Card>
int CardBox<Card>::get_storage() const {
    return storage_;
}

template <class Card>
int CardBox<Card>::get_cards_number() const {
    return cards_number_;
}

#endif  // CARD_BOX_HPP