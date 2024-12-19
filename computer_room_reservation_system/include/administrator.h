#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>

#include "identity.h"

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
};

#endif  // ADMINISTRATOR_H