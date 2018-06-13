#include "DeleteItemOption.h"
#include "../../utils/console.h"
#include "../items/ItemsListMenu.h"

string DeleteItemOption::getDisplayName() {
    return "Видалити";
}

void DeleteItemOption::process() {
    item_->remove();

    waitUntilKeypress("Ви видалили товар: " + item_->get<string>("title"));

    ItemsListMenu menu;
    menu.display();
}

DeleteItemOption::DeleteItemOption(Item *item) : item_(item) {}
