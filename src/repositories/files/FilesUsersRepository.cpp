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
    for(auto user : User::all()) {
        if(user->login != login)
            continue;

        cout << "Користувач з таким логіном вже існує, виберіть інший!" << endl;
        return nullptr;
    }

    User *user = new User(login, password, isAdmin);
    user->save();

    return user;
}
