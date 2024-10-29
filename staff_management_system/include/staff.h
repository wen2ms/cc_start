#ifndef STAFF_H
#define STAFF_H

#include <cstring>
#include <iostream>

class Staff {
  public:
    Staff(const char* id = "unknown", const char* name = "unknown", const char department = '0');

    const char* get_id() const { return id_; }
    const char* get_name() const { return name_; }
    const char get_department() const { return department_; }

    virtual void perform_duty() const = 0;

  protected:
    char id_[10];
    char name_[15];
    char department_;
};

class Employee : public Staff {
  public:
    Employee(const char* id, const char* name, const char department = '1');

    void perform_duty() const override;
};

class Manager : public Staff {
  public:
    Manager(const char* id, const char* name, const char department = '2');

    void perform_duty() const override;
};

class Boss : public Staff {
  public:
    Boss(const char* id, const char* name, const char department = '3');

    void perform_duty() const override;
};

#endif  // STAFF_H