#ifndef KURSACH_MAINMENU_H
#define KURSACH_MAINMENU_H

#include "../Menu.h"

using namespace std;

class MainMenu: public Menu {
private:
    vector<Option*> getOptions() override;
};


#endif //KURSACH_MAINMENU_H
