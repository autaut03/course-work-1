#include "ItemsListMenu.h"
#include "../main/MainMenu.h"
#include "../../models/Item.h"
#include "ItemOption.h"
#include "../CategorizerItem.h"

using namespace std;

vector<MenuItem*> ItemsListMenu::getItems() {
    vector<MenuItem*> options;

    options.emplace_back(new CategorizerItem("ТОВАРИ"));
    for(auto item : Item::all()) {
        options.emplace_back(new ItemOption(item));
    }

    return options;
}

void ItemsListMenu::returnBack() {
    MainMenu menu;
    menu.display();
}
