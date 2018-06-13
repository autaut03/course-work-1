#ifndef KURSACH_ADDITEMOPTION_H
#define KURSACH_ADDITEMOPTION_H


#include "../../Option.h"

class AddItemOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_ADDITEMOPTION_H
