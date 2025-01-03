#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <vector>

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computer_room.h"

class Administrator : public Identity {
  public:
    Administrator(std::string name, std::string password);

    void run() override;

    void add_account();

    void view_all_accounts(); 

    void view_all_rooms(); 

    void clear_all_accounts();

  protected:
    void show_title() override;

  private:
    void init_teachers();
    void init_students();
    void init_computer_rooms();

    std::vector<Student> students_;
    std::vector<Teacher> teachers_;
    std::vector<ComputerRoom> computer_rooms_;
};

#endif  // ADMINISTRATOR_H