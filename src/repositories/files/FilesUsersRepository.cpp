#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "FilesUsersRepository.h"

using namespace std;

User *FilesUsersRepository::getUserMatchingPair(std::string login, std::string password) {
    for(auto user : User::all()) {
        if(user->login != login || user->password != password)
            continue;

        return user;
    }

    return nullptr;
}

User *FilesUsersRepository::createUser(string login, string password, bool isAdmin) {
    User *user = new User(login, password, isAdmin);
    user->save();

    return user;
}
