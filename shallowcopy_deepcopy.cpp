#include <cstring>
#include <iostream>

class ShallowCopy {
  public:
    ShallowCopy(const char str[]) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    ShallowCopy(const ShallowCopy& other) {
        data = other.data;
    }

    ~ShallowCopy() {
        delete[] data;
    }

    char* data;
};

class DeepCopy {
  public:
    DeepCopy(const char str[]) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    DeepCopy(const DeepCopy& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~DeepCopy() {
        delete[] data;
    }

    char* data;
};

int main() {
    std::cout << "I generated an example that explains shallowcopy and deepcopy\n";
    std::cout << "----------------------\n";

    ShallowCopy shallowcopy_a("Dobermann");
    ShallowCopy shallowcopy_b = shallowcopy_a;

    std::cout << "Shallow copy data: " << shallowcopy_a.data << " " << shallowcopy_b.data << '\n';

    shallowcopy_b.data[0] = 'M';
    std::cout << "Modified shallow copy data: " << shallowcopy_a.data << " " << shallowcopy_b.data << '\n';

    DeepCopy deepcopy_a("French Bulldog");
    DeepCopy deepcopy_b = deepcopy_a;

    std::cout << "DeepCopy copy data: " << deepcopy_a.data << " " << deepcopy_b.data << '\n';

    deepcopy_b.data[0] = 'M';
    std::cout << "Modified deepCopy copy data: " << deepcopy_a.data << " " << deepcopy_b.data << '\n';

    std::cout << "----------------------\n";

    return 0;
}