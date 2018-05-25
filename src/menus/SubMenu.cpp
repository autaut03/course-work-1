#include <iostream>
#include "SubMenu.h"
#include "../KeyboardButton.h"

using namespace std;

bool SubMenu::processButtonPress(Option *option, int button) {
    if(button == ESC || button == ARROW_LEFT) {
        returnBack();
        return false;
    }

    return Menu::processButtonPress(option, button);
}
