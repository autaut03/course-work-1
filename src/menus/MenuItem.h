#ifndef KURSACH_MENUITEM_H
#define KURSACH_MENUITEM_H


#include <string>

class MenuItem {
public:
    virtual std::string getDisplayString() = 0;
    virtual bool canBePointedAt() = 0;
    virtual void process() = 0;
};


#endif //KURSACH_MENUITEM_H
