#include "ItemsListOption.h"
#include "../../items/ItemsListMenu.h"

string ItemsListOption::getDisplayName() {
    return "Список товарів";
}

void ItemsListOption::process() {
    ItemsListMenu menu;
    menu.display();
}
