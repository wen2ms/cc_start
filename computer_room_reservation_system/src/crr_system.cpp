#include "crr_system.h"

#include <iostream>

CRRSystem::CRRSystem() {}

void CRRSystem::show_title() {
    std::cout << "-------------- Welcome to Computer Room Reservation System(CRRS) --------------" << std::endl;
    std::cout << std::endl;
    std::cout << "              --------------------------------------------------              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                1. Student                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                2. Teacher                        |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                3. Administrator                  |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "             |                0. Exit                           |              " << std::endl;
    std::cout << "             |                                                  |              " << std::endl;
    std::cout << "              --------------------------------------------------              " << std::endl;
    std::cout << std::endl;   
}