#include "calculator.h"

#include <stdexcept>

double Calculator::add(double a, double b) const {
    return a + b;
}

double Calculator::subtract(double a, double b) const {
    return a - b;
}

double Calculator::mutiply(double a, double b) const {
    return a * b;
}

double Calculator::divide(double a, double b) const {
    if (b == 0) {
        throw std::invalid_argument("Division by zero error");
    }
    return a / b;
}