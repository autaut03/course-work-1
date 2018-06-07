#include <iostream>
#include <synchapi.h>
#include <conio.h>
#include "ItemsListOption.h"
#include "../MainMenu.h"
#include "../../items/ItemsListMenu.h"

string ItemsListOption::getDisplayName() {
    return "Список товарів";
}

void ItemsListOption::process() {
    ItemsListMenu menu;
    menu.display();
}
