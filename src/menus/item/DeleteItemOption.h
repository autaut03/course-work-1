#ifndef KURSACH_DELETEITEM_H
#define KURSACH_DELETEITEM_H


#include "../Option.h"
#include "../../models/Item.h"

class DeleteItemOption: public Option {
public:
    string getDisplayName() override;
    void process() override;

    DeleteItemOption(Item* item);

private:
    Item* item_;
};


#endif //KURSACH_DELETEITEM_H
