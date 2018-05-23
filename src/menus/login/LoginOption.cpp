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

#ifdef __WIN32__
    cin >> password;
    //password = readHiddenInput();
#else
    cin >> password;
#endif

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

    MainMenu menu;
    menu.displayMenu();
}
