#ifndef IDENTITY_H
#define IDENTITY_H

#include <string>

class Identity {
  public:
    Identity(std::string name, std::string password);

    virtual ~Identity();

    virtual void run() = 0;

    std::string name_;
    std::string password_;
  
  protected:
    virtual void show_title() = 0;
};

#endif  // IDENTITY_H