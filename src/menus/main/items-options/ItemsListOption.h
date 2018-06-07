#ifndef KURSACH_ITEMSLISTOPTION_H
#define KURSACH_ITEMSLISTOPTION_H


#include "../../Option.h"

class ItemsListOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_ITEMSLISTOPTION_H
