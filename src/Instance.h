#ifndef KURSACH_INSTANCE_H
#define KURSACH_INSTANCE_H


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


#endif //KURSACH_INSTANCE_H
