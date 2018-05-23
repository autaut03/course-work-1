#ifndef KURSACH_INSTANCE_H
#define KURSACH_INSTANCE_H


#include "models/User.h"

class Instance {
private:
    static Instance* instance;
    User* user;

    // Зробив конструктор приватним, для зручності в IDE і просто для безпеки
    Instance();

    void setEncodings();

public:
    static Instance* getInstance();

    void init();
    void exit();
    bool isLoggedIn();
    User* getUser();
    void setUser(User* user);
};


#endif //KURSACH_INSTANCE_H
