#include <w32api/wincon.h>
#include <clocale>
//#include "Instance.h"
#include "menus/MainMenu.h"

class Instance {
private:
    static Instance* instance;

    // Зробив конструктор приватним, для зручності в IDE і просто для безпеки
    Instance();

    bool loggedIn = false;
    bool administrator = false;

    void setEncodings();

public:
    static Instance* getInstance();

    void init();
    //bool isLoggedIn();
    //bool isAdministrator();
};

// Свого роду перевірка на те, що екземпляр класу ще не був створений
Instance* Instance::instance = nullptr;

Instance* Instance::getInstance() {
    // Тут все просто: при визові цього статичного методу, він провірить, чи вже був створений екземпляр класу чи ні
    // якщо ні - створить його, ну а далі він вернеться куди потрібно.
    if (instance == nullptr)
    {
        instance = new Instance();
    }

    return instance;
}

// Основна логіка запуску програми
void Instance::init() {
    setEncodings();

    MainMenu mainMenu;
    mainMenu.displayMenu();
}

void Instance::setEncodings() {
    setlocale(LC_ALL, "ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

Instance::Instance() {}