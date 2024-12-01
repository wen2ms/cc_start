#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
  public:
    Employee(std::string name = "", int salary = -1);

    std::string get_name() const;

    int get_salary() const;

  private:
    std::string name_;
    int salary_;
};

#endif  // EMPLOYEE_H