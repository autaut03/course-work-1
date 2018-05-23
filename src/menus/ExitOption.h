#ifndef KURSACH_EXITOPTION_H
#define KURSACH_EXITOPTION_H

#include "Option.h"

class ExitOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_EXITOPTION_H
