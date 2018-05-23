#include "console.h"

std::string readHiddenInput() {
    char input[20];

    int i = 0;
    while((input[i] = getchar()) != '\r')
    {
        std::cout << "*";
        i++;
    }

    return std::string(input);
}