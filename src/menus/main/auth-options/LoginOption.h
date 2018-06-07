#ifndef KURSACH_LOGINCHOICE_H
#define KURSACH_LOGINCHOICE_H


#include "../../Option.h"

class LoginOption: public Option {
public:
    string getDisplayName() override;
    void process() override;
};


#endif //KURSACH_LOGINCHOICE_H
