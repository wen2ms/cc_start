#ifndef CRR_SYSTEM
#define CRR_SYSTEM

#include <student.h>

enum IdentifyType {
    kStudent = 1,
    kTeacher,
    kAdministrator
};

class CRRSystem {
  public:
    CRRSystem();

    void show_title();

    void login_in(const std::string& filename, IdentifyType type);
};

#endif  //CRR_SYSTEM