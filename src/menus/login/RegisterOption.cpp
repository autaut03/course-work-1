#include <iostream>
#include "../main/MainMenu.h"
#include "../../utils/console.h"
#include "../../repositories/files/FilesUsersRepository.h"
#include "../../Instance.h"
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
    User* user = repository.createUser(login, password, false);

    if(user == nullptr) {
        cout << "Сталася помилка під час реєстрації :(" << endl;
        return;
    }

    Instance::getInstance()->setUser(user);
    cout << "Ви успішно зареєструвались і авторизувались!" << endl;

    MainMenu menu;
    menu.displayMenu();
}
