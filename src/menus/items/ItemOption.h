#ifndef KURSACH_ITEMOPTION_H
#define KURSACH_ITEMOPTION_H


#include "../Option.h"
#include "../../models/Item.h"

class ItemOption: public Option {
public:
    string getDisplayName() override;
    void process() override;

    ItemOption(Item* item);

private:
    Item* item_;
};


#endif //KURSACH_ITEMOPTION_H
