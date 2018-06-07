#include <iostream>
#include <conio.h>
#include "../MainMenu.h"
#include "../../../utils/console.h"
#include "../../../repositories/files/FilesUsersRepository.h"
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

    FilesUsersRepository repository;
    auto user = repository.createUser(login, password, false);

    if(user == nullptr) {
        waitUntilKeypress("Сталася помилка під час реєстрації :(");

        MainMenu menu;
        menu.display();
        return;
    }

    Instance::getInstance()->setUser(user);
    waitUntilKeypress("Ви успішно зареєструвались і авторизувались!");

    MainMenu menu;
    menu.display();
}
