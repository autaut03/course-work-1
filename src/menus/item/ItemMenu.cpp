#include "ItemMenu.h"
#include "../items/ItemsListMenu.h"
#include "../DummyItem.h"
#include "../CategorizerItem.h"
#include "BuyItemOption.h"
#include "DeleteItemOption.h"
#include "../../Instance.h"

using namespace std;

vector<MenuItem*> ItemMenu::getItems() {
    vector<MenuItem*> options;

    options.emplace_back(new DummyItem("\n " + item_->get<string>("title") + "\n - " + item_->get<string>("description")));

    if(Instance::getInstance()->isLoggedIn()) {
        options.emplace_back(new CategorizerItem("ДІЇ"));
        options.emplace_back(new BuyItemOption(item_));
        if(Instance::getInstance()->getUser()->get<bool>("isAdmin")) {
            options.emplace_back(new DeleteItemOption(item_));
        }
    }

    return options;
}

void ItemMenu::returnBack() {
    ItemsListMenu menu;
    menu.display();
}

ItemMenu::ItemMenu(Item *item) : item_(item) {}
