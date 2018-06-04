#ifndef KURSACH_LOGOUTOPTION_H
#define KURSACH_LOGOUTOPTION_H


#include "../Option.h"

class LogOutOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_LOGOUTOPTION_H
