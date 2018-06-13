#ifndef KURSACH_BUYITEM_H
#define KURSACH_BUYITEM_H


#include "../Option.h"
#include "../../models/Item.h"

class BuyItemOption: public Option {
public:
    string getDisplayName() override;
    void process() override;

    BuyItemOption(Item* item);

private:
    Item* item_;
};


#endif //KURSACH_BUYITEM_H
