#ifndef KURSACH_MENU_H
#define KURSACH_MENU_H

#include <vector>
#include <string>
#include "Option.h"

using namespace std;

class Menu {
private:
    virtual vector<Option*> getOptions() = 0;

    vector<Option*> getOptionsInternal();
    void clearScreen();
    void printSeparatorBefore();
    void printOptions(vector<Option*> &options);
    void printSeparatorAfter();
    int askForChoice(vector<Option*> &options, int optionsCount);

protected:
    virtual void addAdditionalOptions(vector<Option*> &options);

public:
    void displayMenu();
};


#endif //KURSACH_MENU_H
