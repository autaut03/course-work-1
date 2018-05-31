#include <iostream>
#include <limits>
#include <synchapi.h>
#include "Menu.h"
#include "ExitOption.h"
#include "../KeyboardButton.h"
#include "../Instance.h"

using namespace std;

void Menu::clearScreen() {
#ifdef __MINGW__
    system("cls");
#else
    system("clear");
#endif
}

void Menu::printSeparatorBefore() {
    cout << "---==== ІНТЕРНЕТ МАГАЗИН ІГРОВИХ КЛЮЧІВ ТА АКАУНТІВ ====---" << endl;

    if(Instance::getInstance()->isLoggedIn()) {
        User* user = Instance::getInstance()->getUser();
        cout << "          Авторизовано як: " << user->get<string>("login") << " - " << user->getRoleDisplayName() << "" << endl;
        printSeparatorAfter();
    }
}

void Menu::printOptions(vector<Option*> &options) {
    for(int i = 0; i < options.size(); i++) {
        cout << " " << (pointingAtOption == i ? "> " : " ") << options[i]->getDisplayName() << endl;
    }
}

void Menu::printSeparatorAfter() {
    cout << "---=====================================================---" << endl;
}

vector<Option*> Menu::getOptionsInternal() {
    vector<Option*> options = getOptions();
    options.emplace_back(new ExitOption);

    return options;
}

void Menu::displayMenu() {
    vector<Option*> options = getOptionsInternal();
    int optionsCount = options.size();

    drawMenu(options);

    bool keepRunning = true;
    while(keepRunning) {
        int button = getchar();

        switch(button) {
            case ARROW_UP:
                if(pointingAtOption == 0) {
                    break;
                }

                pointingAtOption--;
                drawMenu(options);
                break;
            case ARROW_DOWN:
                if(pointingAtOption + 1 == optionsCount) {
                    break;
                }

                pointingAtOption++;
                drawMenu(options);
                break;
            case ENTER:
            case ARROW_RIGHT:
                keepRunning = false;
                options.at(pointingAtOption)->process();
                break;
            default:
                keepRunning = processButtonPress(options.at(pointingAtOption), button);
                break;
        }
    }
}

bool Menu::processButtonPress(Option* option, int button) {
    return true;
}


void Menu::drawMenu(vector<Option*> &options) {
    clearScreen();
    printSeparatorBefore();
    printOptions(options);
    printSeparatorAfter();
}