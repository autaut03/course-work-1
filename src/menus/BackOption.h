#ifndef KURSACH_BACKOPTION_H
#define KURSACH_BACKOPTION_H

#include "Option.h"
#include "SubMenu.h"

class BackOption: public Option {
private:
    SubMenu* menu;

public:
    string getDisplayName() override;
    void process() override;

    BackOption(SubMenu* menu);
};


#endif //KURSACH_BACKOPTION_H
