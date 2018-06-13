#include <iostream>
#include "../MainMenu.h"
#include "../../../utils/console.h"
#include "../../../Instance.h"
#include "RegisterOption.h"

using namespace std;

string RegisterOption::getDisplayName() {
    return "Зареєструватись";
}

void RegisterOption::process() {
    cout << "Введіть логін: ";
    string login;
    cin >> login;

    cout << "Введіть пароль: ";
    string password;
    cin >> password;

    for(auto user : User::all()) {
        if(user->get<string>("login") != login)
            continue;

        waitUntilKeypress("Користувач з таким логіном вже існує, виберіть інший!");

        MainMenu menu;
        menu.display();
        return;
    }

    auto user = new User();
    user->set("login", login);
    user->set("password", password);
    user->set("isAdmin", false);
    user->save();

    Instance::getInstance()->setUser(user);
    waitUntilKeypress("Ви успішно зареєструвались і авторизувались!");

    MainMenu menu;
    menu.display();
}
