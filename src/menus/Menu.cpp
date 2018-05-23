#include <iostream>
#include <limits>
#include <synchapi.h>
#include "Menu.h"
#include "ExitOption.h"

using namespace std;

void Menu::clearScreen() {
#ifdef __WIN32__
    system("cls");
#else
    //cout << "\033[2J\033[1;1H";
    cout << "\x1B[2J\x1B[H";
#endif
}

void Menu::printSeparatorBefore() {
    cout << "---==== ІНТЕРНЕТ МАГАЗИН ІГРОВИХ КЛЮЧІВ ТА АКАУНТІВ ====---" << endl;
}

void Menu::printOptions(vector<Option*> &options) {
    for(int i = 0; i < options.size(); i++) {
        cout << " " << i + 1 << " - " << options[i]->getDisplayName() << endl;
    }
}

void Menu::printSeparatorAfter() {
    cout << "---=====================================================---" << endl;
}

vector<Option*> Menu::getOptionsInternal() {
    vector<Option*> options = getOptions();
    addAdditionalOptions(options);
    options.emplace_back(new ExitOption);

    return options;
}

void Menu::addAdditionalOptions(vector<Option*> &options) {}


void Menu::displayMenu() {
    Sleep(1000);

    vector<Option*> options = getOptionsInternal();
    int optionsCount = options.size();

    clearScreen();
    printSeparatorBefore();
    printOptions(options);
    printSeparatorAfter();
    int choice = askForChoice(options, optionsCount);

    options.at(choice - 1)->process();
}

int Menu::askForChoice(vector<Option*> &options, int optionsCount) {
    int choice;
    cout << "Виберіть пункт меню, в який хочете попасти: ";
    while(!(cin >> choice) || choice < 1 || choice > optionsCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Можливі варіанти: 1-" << optionsCount << ". Спробуйте ще раз: ";
    }

    cout << "Ви вибрали пункт #" << choice << ": " << options[choice - 1]->getDisplayName() << endl;

    return choice;
}