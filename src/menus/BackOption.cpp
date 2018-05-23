#include "BackOption.h"

string BackOption::getDisplayName() {
    return "Назад";
}

void BackOption::process() {
    menu->openPreviousMenu();
}

BackOption::BackOption(SubMenu *menu) : menu(menu) {}
