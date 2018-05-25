#ifndef KURSACH_LOGINMENU_H
#define KURSACH_LOGINMENU_H

#include "../SubMenu.h"

using namespace std;

class AuthMenu: public SubMenu {
private:
    vector<Option*> getOptions() override;

public:
    void returnBack() override;
};


#endif //KURSACH_LOGINMENU_H
