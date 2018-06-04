#include <iostream>
#include "SubMenu.h"
#include "../utils/console.h"

using namespace std;

bool SubMenu::processButtonPress(MenuItem *option, int button) {
    if(button == ESC || button == ARROW_LEFT) {
        returnBack();
        return false;
    }

    return Menu::processButtonPress(option, button);
}

void SubMenu::printSeparatorAfter() {
    cout << "\n ↑ - вверх, ↓ - вниз, → або ENTER - вибрати, ← або ESC - назад" << endl;
    cout << "---=====================================================---" << endl;
}