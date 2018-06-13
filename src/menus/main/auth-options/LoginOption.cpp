#include "LoginOption.h"
#include <iostream>
#include "../MainMenu.h"
#include "../../../utils/console.h"
#include "../../../Instance.h"
#include <conio.h>

using namespace std;

string LoginOption::getDisplayName() {
    return "Авторизуватись";
}

void LoginOption::process() {
    cout << "Введіть логін: ";
    string login;
    cin >> login;

    cout << "Введіть пароль: ";
    string password;
    cin >> password;
    //password = readHiddenInput();

    User* foundUser = nullptr;
    for(auto user : User::all()) {
        if(user->get<string>("login") != login || user->get<string>("password") != password)
            continue;

        foundUser = user;
    }

    if(foundUser == nullptr) {
        waitUntilKeypress("Логін або пароль було введено неправильно");

        MainMenu menu;
        menu.display();
        return;
    }

    Instance::getInstance()->setUser(foundUser);
    waitUntilKeypress("Ви успішно авторизувались!");

    MainMenu menu;
    menu.display();
}
