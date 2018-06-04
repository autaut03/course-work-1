#include "console.h"
#include <conio.h>

std::string readHiddenInput() {
    char input[20];

    int i = 0;
    while((input[i] = getch()) != '\r')
    {
        std::cout << "*";
        i++;
    }

    return std::string(input);
}

void clearScreen() {
    system("cls");
}

void waitUntilKeypress(std::string message) {
    std::cout << message << " (нажміть будь яку клавішу для продовження)" << std::endl;
    getch();
}