#include <iostream>
#include <string>

template <class SrcName = int>
class File {
  public: 
    File(SrcName src_name) : src_name_(src_name) {}

    SrcName src_name_;  
};

void run(File<std::string>& file) {
    std::cout << "Run " << file.src_name_ << std::endl;
}

template <class T>
void run(File<T>& file) {
    std::cout << "Run " << file.src_name_ << std::endl;
}

template <class T>
void run(T& file) {
    std::cout << "Run " << file.src_name_ << std::endl;
}

int main() {
    std::cout << "I generated an example of class template as function arguments\n";
    std::cout << "------------------------------\n";

    File<std::string> file("./file.txt");

    run(file);

    std::cout << "------------------------------\n";

    return 0;
}