#include "src/Instance.h"

int main() {
    try {
        // Отримаєм екземпляр головного класу програми, який є сінглтоном
        Instance *instance = Instance::getInstance();

        instance->init();

        return EXIT_SUCCESS;
    } catch (const std::exception&) {
        return EXIT_FAILURE;
    }
}