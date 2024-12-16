#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>

#include "identity.h"

class Administrator : public Identity {
  public:
    Administrator(std::string name, std::string password);

};

#endif  // ADMINISTRATOR_H