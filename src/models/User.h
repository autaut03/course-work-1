#ifndef KURSACH_USER_H
#define KURSACH_USER_H

#include <string>
#include "../orm/Model.tpp"

using namespace std;

class User: public Model<User> {
private:
    vector<string> toRowData() override;

public:
    string login, password;
    bool isAdmin;

    User(string login, string password, bool isAdmin);

    string getRoleDisplayName();
};

#endif //KURSACH_USER_H