#ifndef KURSACH_MENU_H
#define KURSACH_MENU_H

#include <vector>
#include <string>
#include "Option.h"

using namespace std;

class Menu {
private:
    int pointingAtOption = 0;

    virtual vector<Option*> getOptions() = 0;

    vector<Option*> getOptionsInternal();
    void clearScreen();
    void printSeparatorBefore();
    void printOptions(vector<Option*> &options);
    void printSeparatorAfter();
    void drawMenu(vector<Option*> &options);

protected:
    // If false returned, then the cycle should be stopped (menu changed)
    virtual bool processButtonPress(Option* option, int button);

public:
    void displayMenu();
};


#endif //KURSACH_MENU_H
