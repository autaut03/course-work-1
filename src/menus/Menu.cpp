#include <iostream>
#include <limits>
#include <conio.h>
#include <algorithm>
#include "Menu.h"
#include "ExitOption.h"
#include "../Instance.h"
#include "../utils/console.h"
#include "DummyItem.h"
#include "CategorizerItem.h"

using namespace std;

void Menu::printSeparatorBefore() {
    cout << "---==== ІНТЕРНЕТ МАГАЗИН ІГРОВИХ КЛЮЧІВ ТА АКАУНТІВ ====---" << endl;

    if(Instance::getInstance()->isLoggedIn()) {
        auto user = Instance::getInstance()->getUser();
        cout << " Авторизовано як: " << user->get<string>("login") << " - " << user->getRoleDisplayName() << endl;
    }
}

void Menu::printItems() {
    for (auto &item : items) {
        if(item->canBePointedAt()) {
            auto index = distance(pointableItems.begin(), find(pointableItems.begin(), pointableItems.end(), item));
            cout << " " << (pointingAtOption == index ? "> " : " ");
        }
        cout << item->getDisplayString() << endl;
    }
}

void Menu::printSeparatorAfter() {
    cout << "\n ↑ - вверх, ↓ - вниз, → або ENTER - вибрати" << endl;
    cout << "---=====================================================---" << endl;
}

void Menu::display() {
    parseItems();
    draw();

    bool keepRunning = true;
    while(keepRunning) {
        int button = getch();

        switch(button) {
            case ARROW_UP:
                if(pointingAtOption == 0) {
                    pointingAtOption = pointableItems.size() - 1;
                } else {
                    pointingAtOption--;
                }

                draw();
                break;
            case ARROW_DOWN:
                if(pointingAtOption + 1 == pointableItems.size()) {
                    pointingAtOption = 0;
                } else {
                    pointingAtOption++;
                }

                draw();
                break;
            case ENTER:
            case ARROW_RIGHT:
                keepRunning = false;
                pointableItems.at(pointingAtOption)->process();
                break;
            default:
                keepRunning = processButtonPress(pointableItems.at(pointingAtOption), button);
                break;
        }
    }
}

bool Menu::processButtonPress(MenuItem* option, int button) {
    return true;
}

void Menu::parseItems() {
    items = getItems();
    items.emplace_back(new CategorizerItem("ІНШЕ"));
    items.emplace_back(new ExitOption);

    for(auto item : items) {
        if(! item->canBePointedAt()) {
            continue;
        }

        pointableItems.emplace_back(item);
    }
}


void Menu::draw() {
    clearScreen();
    printSeparatorBefore();
    printItems();
    printSeparatorAfter();
}