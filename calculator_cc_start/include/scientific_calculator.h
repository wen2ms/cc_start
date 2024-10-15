#ifndef SCIENTIFIC_CALCULATOR_H
#define SCIENTIFIC_CALCULATOR_H

#include <cmath>

#include "calculator.h"

class ScientificCalculator : public Calculator {
  public:
    double power(double base, double exponent) const;
};

#endif  // SCIENTIFIC_CALCULATOR_H