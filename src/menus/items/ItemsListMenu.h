#ifndef KURSACH_ITEMSLISTMENU_H
#define KURSACH_ITEMSLISTMENU_H

#include "../SubMenu.h"

class ItemsListMenu: public SubMenu {
private:
    vector<MenuItem*> getItems() override;

public:
    void returnBack() override;
};


#endif //KURSACH_ITEMSLISTMENU_H
