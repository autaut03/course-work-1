#include "ItemsListMenu.h"
#include "../main/MainMenu.h"

using namespace std;

vector<MenuItem*> ItemsListMenu::getItems() {
    vector<MenuItem*> options;

    return options;
}

void ItemsListMenu::returnBack() {
    MainMenu menu;
    menu.display();
}
