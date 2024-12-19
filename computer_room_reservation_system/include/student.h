#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "identity.h"

class Student : public Identity {
  public:
    Student(std::string name, std::string password, int id);

    void run() override;

    void apply();

    void view_mine();

    void view_all();

    void cancle();

    int id_;

  protected:
    void show_title() override;
};

#endif  // STUDENT_H