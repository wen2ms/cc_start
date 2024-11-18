#include <iostream>
#include <string>

void reverse_sentence(std::string& sentence) {
    int space_index = sentence.find(' ');

    if (space_index == std::string::npos) {
        return;
    } else {
        int cursor = space_index;
        while (cursor != sentence.length()) {

            std::string word = sentence.substr(0, space_index);

            sentence.insert(sentence.length() - cursor + space_index, ' ' + word);

            sentence.erase(0, space_index + 1);

            space_index = sentence.find(' ');

            cursor += (space_index + 1);
        }
    }
}

int main() {
    std::cout << "I generated an example that blends the substr, insert and erase\n";
    std::cout << "---------------------------------\n";

    std::cout << "Please enter a sentance: ";
    std::string sentence;

    std::getline(std::cin, sentence);

    reverse_sentence(sentence);

    std::cout << "Reverse sentence: " << sentence << '\n';

    std::cout << "---------------------------------\n";

    return 0;
}