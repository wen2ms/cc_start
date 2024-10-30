#ifndef STAFF_H
#define STAFF_H

#include <iostream>

class Staff {
  public:
    Staff(std::string id = "unknown", std::string name = "unknown", const char department = '0');

    virtual ~Staff() {}

    std::string get_id() const {
        return id_;
    }
    std::string get_name() const {
        return name_;
    }
    const char get_department() const {
        return department_;
    }

    virtual void perform_duty() const = 0;

  protected:
    std::string id_;
    std::string name_;
    char department_;
};

class Employee : public Staff {
  public:
    Employee(std::string id, std::string name, const char department = '1');

    void perform_duty() const override;
};

class Manager : public Staff {
  public:
    Manager(std::string id, std::string name, const char department = '2');

    void perform_duty() const override;
};

class Boss : public Staff {
  public:
    Boss(std::string id, std::string name, const char department = '3');

    void perform_duty() const override;
};

#endif  // STAFF_H