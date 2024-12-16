#include "teacher.h"

Teacher::Teacher(std::string name, std::string password, int id) : Identity(name, password), id_(id) {}