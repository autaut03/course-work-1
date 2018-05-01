#include <iostream>
#include "Menu.h"

void Menu::clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}

void Menu::printBefore() {
    std::cout << " ---==== ІНТЕРНЕТ МАГАЗИН ІГРОВИХ КЛЮЧІВ ТА АКАУНТІВ ====--- ";
}

void Menu::printAfter() {
    std::cout << " ---=====================================================--- ";
}

void Menu::displayMenu() {
    clearScreen();
    printBefore();
    display();
    printAfter();
}
