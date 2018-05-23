#ifndef KURSACH_SUBMENU_H
#define KURSACH_SUBMENU_H

#include "Menu.h"

using namespace std;

class SubMenu: public Menu {
protected:
    void addAdditionalOptions(vector<Option*> &options) override;

public:
    virtual void openPreviousMenu() = 0;
};


#endif //KURSACH_SUBMENU_H
