#include "utilities.h"

#include <iostream>

namespace utilities {
void wait_any_key() {
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}
}