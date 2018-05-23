#include "AuthMenuOption.h"
#include "../login/AuthMenu.h"

string AuthMenuOption::getDisplayName() {
    return "Авторизація/реєстрація";
}

void AuthMenuOption::process() {
    AuthMenu menu;
    menu.displayMenu();
}
