#include "ItemOption.h"
#include "../item/ItemMenu.h"

string ItemOption::getDisplayName() {
    return item_->get<string>("title");
}

void ItemOption::process() {
    ItemMenu menu(item_);
    menu.display();
}

ItemOption::ItemOption(Item *item) : item_(item) {}
