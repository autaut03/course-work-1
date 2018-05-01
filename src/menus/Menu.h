#ifndef KURSACH_MENU_H
#define KURSACH_MENU_H


class Menu {
private:
    // Абстрактний метод кожного Меню, що відобразить його
    virtual void display() = 0;

    void clearScreen();
    void printBefore();
    void printAfter();

public:
    // Абстрактний метод кожного Меню, що відобразить його
    void displayMenu();
};


#endif //KURSACH_MENU_H
