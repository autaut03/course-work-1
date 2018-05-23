#ifndef KURSACH_AUTHMENUOPTION_H
#define KURSACH_AUTHMENUOPTION_H


#include "../Option.h"

class AuthMenuOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_AUTHMENUOPTION_H
