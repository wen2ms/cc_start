#ifndef IDENTITY_H
#define IDENTITY_H

#include <string>

class Identity {
  public:
    Identity(std::string name, std::string password);

    virtual void run() = 0;

    std::string name_;
    std::string password_;
};

enum ReservationState {
    kFailed = -1,
    kReviewing = 0,
    kPassed = 1
};

#endif  // IDENTITY_H