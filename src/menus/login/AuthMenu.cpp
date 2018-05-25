#include <iostream>
#include "AuthMenu.h"
#include "../main/MainMenu.h"
#include "LoginOption.h"
#include "RegisterOption.h"

using namespace std;

vector<Option*> AuthMenu::getOptions() {
    return {
            new LoginOption,
            new RegisterOption
    };
}

void AuthMenu::returnBack() {
    MainMenu menu;
    menu.displayMenu();
}
