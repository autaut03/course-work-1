#include <iostream>
#include "src/Instance.cpp"

using namespace std;


int main() {
    // Отримаєм екземпляр головного класу програми, який є сінглтоном
    Instance* instance = Instance::getInstance();

    instance->init();
}