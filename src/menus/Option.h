#ifndef KURSACH_CHOICE_H
#define KURSACH_CHOICE_H

#include <string>

using namespace std;

class Option {
public:
    virtual string getDisplayName() = 0;
    virtual void process() = 0;
};


#endif //KURSACH_CHOICE_H
