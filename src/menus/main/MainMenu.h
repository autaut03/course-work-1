#ifndef KURSACH_MAINMENU_H
#define KURSACH_MAINMENU_H

#include "../Menu.h"
#include "../MenuItem.h"

using namespace std;

class MainMenu: public Menu {
private:
    vector<MenuItem*> getItems() override;
};


#endif //KURSACH_MAINMENU_H
