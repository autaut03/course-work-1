#include "LoginOption.h"
#include <iostream>
#include "../main/MainMenu.h"
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

    Instance* instance = Instance::getInstance();

    FilesUsersRepository repository;
    instance->setUser(
            repository.getUserMatchingPair(login, password)
    );

    if(!instance->isLoggedIn()) {
        cout << "Сталася помилка під час авторизації :(" << endl;
        //displayMenu();
        return;
    }

    cout << "Ви успішно авторизувались!" << endl;

    Sleep(1000);

    MainMenu menu;
    menu.displayMenu();
}
