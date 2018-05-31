#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "FilesUsersRepository.h"

using namespace std;

User *FilesUsersRepository::getUserMatchingPair(std::string login, std::string password) {
    for(auto user : User::all()) {
        if(user->get<string>("login") != login || user->get<string>("password") != password)
            continue;

        return user;
    }

    return nullptr;
}

User *FilesUsersRepository::createUser(string login, string password, bool isAdmin) {
    for(auto user : User::all()) {
        if(user->get<string>("login") != login)
            continue;

        cout << "Користувач з таким логіном вже існує, виберіть інший!" << endl;
        return nullptr;
    }

    User *user = new User();
    user->set("login", login);
    user->set("password", password);
    user->set("isAdmin", isAdmin);
    user->save();

    return user;
}
