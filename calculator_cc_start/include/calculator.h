#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
  public:
    virtual double add(double a, double b) const;
    virtual double subtract(double a, double b) const;
    virtual double mutiply(double a, double b) const;
    virtual double divide(double a, double b) const;
    virtual ~Calculator() {}
};

#endif  // CALCULATOR_H