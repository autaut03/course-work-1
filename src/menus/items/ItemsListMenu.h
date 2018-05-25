#ifndef KURSACH_ITEMSLISTMENU_H
#define KURSACH_ITEMSLISTMENU_H


class ItemsListMenu: public SubMenu {
private:
    vector<Option*> getOptions() override;

public:
    void returnBack() override;
};


#endif //KURSACH_ITEMSLISTMENU_H
