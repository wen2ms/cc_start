#ifndef SCIENTIFIC_CALCULATOR_H
#define SCIENTIFIC_CALCULATOR_H

#include "calculator.h"

#include <cmath>

class ScientificCalculator : public Calculator {
  public:
    double power(double base, double exponent) const;
};

#endif // SCIENTIFIC_CALCULATOR_H