#ifndef KURSACH_SEPARATORITEM_H
#define KURSACH_SEPARATORITEM_H


#include "Option.h"

class DummyItem: public MenuItem {
public:
    DummyItem();
    DummyItem(std::string msg);

    std::string getDisplayString() override;
    bool canBePointedAt() override;
    void process() override;

private:
    std::string msg_ = "";
};


#endif //KURSACH_SEPARATORITEM_H
