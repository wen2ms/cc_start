#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "identity.h"

class Student : public Identity {
  public:
    Student(std::string name, std::string password, int id);

    void run() override;

    int id_;
};

#endif  // STUDENT_H