#include <iostream>
#include <synchapi.h>
#include <conio.h>
#include "LogOutOption.h"
#include "../MainMenu.h"
#include "../../../Instance.h"
#include "../../../utils/console.h"

string LogOutOption::getDisplayName() {
    return "Вийти з аккаунта";
}

void LogOutOption::process() {
    Instance::getInstance()->setUser(nullptr);
    waitUntilKeypress("Ви вийшли з аккаунта!");

    MainMenu menu;
    menu.display();
}
