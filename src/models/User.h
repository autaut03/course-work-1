#ifndef KURSACH_USER_H
#define KURSACH_USER_H

#include <string>
#include "../orm/Model.hpp"

using namespace std;

class User: public Model<User> {
public:
    User(const unordered_map<string, string> &data);

    string getRoleDisplayName();
};

#endif //KURSACH_USER_H