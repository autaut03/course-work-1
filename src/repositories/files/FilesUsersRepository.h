#ifndef KURSACH_FILESUSERSREPOSITORY_H
#define KURSACH_FILESUSERSREPOSITORY_H

#include <string>
#include "../../models/User.h"

using namespace std;

class FilesUsersRepository {
public:
    User* getUserMatchingPair(string login, string password);
    User* createUser(string login, string password, bool isAdmin);

};


#endif //KURSACH_FILESUSERSREPOSITORY_H
