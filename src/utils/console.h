#ifndef KURSACH_CONSOLE_H
#define KURSACH_CONSOLE_H

#include <string>
#include <windows.h>
#include <iostream>

enum KeyboardButton {
    ARROW_LEFT = 75,
    ARROW_RIGHT = 77,
    ARROW_UP = 72,
    ARROW_DOWN = 80,
    ENTER = 13,
    ESC = 27
};

std::string readHiddenInput();
void clearScreen();
void waitUntilKeypress(std::string message);

#endif //KURSACH_CONSOLE_H
