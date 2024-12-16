#ifndef IDENTITY_H
#define IDENTITY_H

#include <string>

class Identity {
  public:
    Identity(std::string name, std::string password);

    virtual void run() = 0;

    virtual void show_title() = 0;

    std::string name_;
    std::string password_;
};

#endif  // IDENTITY_H