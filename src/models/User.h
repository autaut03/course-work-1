#ifndef KURSACH_USER_H
#define KURSACH_USER_H

#include <string>
#include "../orm/Model.hpp"

using namespace std;

class User: public Model<User> {
    using Model<User>::Model;
public:
    string getRoleDisplayName();
};

#endif //KURSACH_USER_H