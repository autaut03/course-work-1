#ifndef KURSACH_MENU_H
#define KURSACH_MENU_H

#include <vector>
#include <string>
#include "Option.h"

using namespace std;

class Menu {
private:
    int pointingAtOption = 0;
    vector<MenuItem*> items;
    vector<MenuItem*> pointableItems;

    virtual vector<MenuItem*> getItems() = 0;
    void parseItems();

    void printSeparatorBefore();
    void printItems();
    virtual void printSeparatorAfter();
    void draw();

protected:
    // If false returned, then the cycle should be stopped (menu changed)
    virtual bool processButtonPress(MenuItem* option, int button);

public:
    void display();
};


#endif //KURSACH_MENU_H
