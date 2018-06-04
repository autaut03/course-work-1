#include "LoginOption.h"
#include <iostream>
#include <conio.h>
#include "MainMenu.h"
#include "../../utils/console.h"
#include "../../repositories/files/FilesUsersRepository.h"
#include "../../Instance.h"

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

    FilesUsersRepository repository;
    Instance* instance = Instance::getInstance();

    instance->setUser(
            repository.getUserMatchingPair(login, password)
    );

    if(!instance->isLoggedIn()) {
        waitUntilKeypress("Логін або пароль було введено неправильно");

        MainMenu menu;
        menu.display();
        return;
    }

    waitUntilKeypress("Ви успішно авторизувались!");

    MainMenu menu;
    menu.display();
}
