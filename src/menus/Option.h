#ifndef KURSACH_CHOICE_H
#define KURSACH_CHOICE_H

#include <string>
#include "MenuItem.h"

using namespace std;

class Option: public MenuItem {
public:
    virtual string getDisplayName() = 0;
    bool canBePointedAt() override;
    std::string getDisplayString() override;
};


#endif //KURSACH_CHOICE_H
