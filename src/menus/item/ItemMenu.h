#ifndef KURSACH_ITEMMENU_H
#define KURSACH_ITEMMENU_H

#include "../SubMenu.h"
#include "../../models/Item.h"

class ItemMenu: public SubMenu {
private:
    vector<MenuItem*> getItems() override;

    Item* item_;

public:
    void returnBack() override;

    ItemMenu(Item* item);
};


#endif //KURSACH_ITEMMENU_H
