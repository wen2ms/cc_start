#include <iostream>
#include <string>

template <class SrcNameType = std::string>
class File {
  public:
    File(SrcNameType src_name) : src_name_(src_name) {}

    virtual void run() const {
        std::cout << "Run " << src_name_ << std::endl;
    }    

  private:
    SrcNameType src_name_;
};

int main() {
    std::cout << "I generated an example of class template\n";
    std::cout << "------------------------------\n";

    File<int> file_int(0);

    file_int.run();

    File file_str("filename");

    file_str.run();

    std::cout << "------------------------------\n";

    return 0;
}