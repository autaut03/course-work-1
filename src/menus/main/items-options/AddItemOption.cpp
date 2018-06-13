#include "AddItemOption.h"
#include "../../../utils/console.h"
#include "../MainMenu.h"
#include "../../../models/Item.h"

string AddItemOption::getDisplayName() {
    return "Додати товар";
}

void AddItemOption::process() {
    cout << "Введіть заголовок: ";
    string title;
    cin >> title;

    cout << "Введіть опис: ";
    string description;
    cin >> description;

    auto user = new Item();
    user->set("title", title);
    user->set("description", description);
    user->save();

    waitUntilKeypress("Ви добавили новий товар!");

    MainMenu menu;
    menu.display();
}
