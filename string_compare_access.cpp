#include <iostream>
#include <string>

int main() {
    std::cout << "I generated a example that compare and access string\n";
    std::cout << "---------------------------\n";

    std::string original_sentence = "I have a dream that one day every valley shall be exsalted";
    std::string new_sentence(original_sentence);

    int index = new_sentence.find("every");

    new_sentence[index] = 's';
    new_sentence[index + 1] = 'i';
    new_sentence[index + 2] = 'n';
    new_sentence[index + 3] = 'g';

    new_sentence.at(index + 4) = 'l';
    new_sentence.at(index + 5) = 'e';

    std::cout << new_sentence << std::endl;

    if (new_sentence.compare(original_sentence) > 0) {
        std::cout << "new_sentence is greater than original_sentence\n";
    } else if (new_sentence.compare(original_sentence) < 0 ) {
        std::cout << "new_sentence is small than original_sentence\n";
    } else if (new_sentence.compare(original_sentence) == 0) {
        std::cout << "new_sentence is equal original_sentence\n";
    }

    std::cout << "---------------------------\n";
    
    return 0;
}