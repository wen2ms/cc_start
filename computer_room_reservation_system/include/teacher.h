#ifndef TEACHER_H
#define TEACHER_H

#include <string>

#include "identity.h"

class Teacher : public Identity {
  public:
    Teacher(std::string name, std::string password, int id);

    void run() override;

    void view_all();

    void review(); 

    int id_;

  protected:
    void show_title() override;
};

#endif  // TEACHER_H