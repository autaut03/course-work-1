#include <clocale>
#include <windows.h>
#include <iostream>
#include "Instance.h"
#include "menus/main/MainMenu.h"

// Свого роду перевірка на те, що екземпляр класу ще не був створений
Instance* Instance::instance = nullptr;

Instance* Instance::getInstance() {
    // Тут все просто: при визові цього статичного методу, він провірить, чи вже був створений екземпляр класу чи ні
    // якщо ні - створить його, ну а далі він вернеться куди потрібно.
    if (instance == nullptr)
    {
        instance = new Instance();
    }

    return instance;
}

// Основна логіка запуску програми
void Instance::init() {
    setEncodings();

    MainMenu mainMenu;
    mainMenu.display();
}

void Instance::exit() {
    cout << "Виходимо з програми.." << endl;
    // Цей ексепшен буде зловлений в методі main, той верне EXIT_FAILURE і программа сама почистить за собою пам'ять.
    throw std::exception();
}

void Instance::setEncodings() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP( CP_UTF8 );
    setvbuf(stdout, nullptr, _IOFBF, 1000);
}

Instance::Instance() {
    user = nullptr;
}

bool Instance::isLoggedIn() {
    return user != nullptr;
}

User* Instance::getUser() {
    return user;
}

void Instance::setUser(User* userL) {
    user = userL;
}
