#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "identity.h"
#include "computer_room.h"

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

  private:
    void init_computer_rooms();

    std::vector<ComputerRoom> computer_rooms_;
};

#endif  // STUDENT_H