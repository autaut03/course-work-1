#ifndef KURSACH_SUBMENU_H
#define KURSACH_SUBMENU_H

#include "Menu.h"

using namespace std;

class SubMenu: public Menu {
protected:
    bool processButtonPress(Option* option, int button) override;

public:
    virtual void returnBack() = 0;
};


#endif //KURSACH_SUBMENU_H
