#ifndef KURSACH_REGISTERCHOICE_H
#define KURSACH_REGISTERCHOICE_H


#include "../Option.h"

class RegisterOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_REGISTERCHOICE_H
