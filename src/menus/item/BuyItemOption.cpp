#include "BuyItemOption.h"
#include "../../utils/console.h"
#include "../items/ItemsListMenu.h"

string BuyItemOption::getDisplayName() {
    return "Купити";
}

void BuyItemOption::process() {
    // Тут логіка добавлення товару в список "куплених" користувача

    waitUntilKeypress("Ви купили товар: " + item_->get<string>("title"));

    ItemsListMenu menu;
    menu.display();
}

BuyItemOption::BuyItemOption(Item *item) : item_(item) {}
