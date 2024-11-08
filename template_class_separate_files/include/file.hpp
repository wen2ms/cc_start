#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <typeinfo>

template <class SrcType>
class File {
  public:
    File(SrcType src_name);

    virtual void run();
  private:
    SrcType src_name_;
};

template <class SrcType>
File<SrcType>::File(SrcType src_name) : src_name_(src_name) {}

template<class SrcType>
void File<SrcType>::run() {
    std::cout << "SrcType is " << typeid(SrcType).name() << std::endl;
}

#endif  // FILE_HPP