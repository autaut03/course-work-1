#include "ItemsListMenu.h"
#include "../main/MainMenu.h"

using namespace std;

vector<Option*> ItemsListMenu::getOptions() {
    return {

    };
}

void ItemsListMenu::returnBack() {
    MainMenu menu;
    menu.displayMenu();
}
