#include "src/Instance.h"
#include "src/utils/console.h"

int main() {
    try {
        // Отримаєм екземпляр головного класу програми, який є сінглтоном
        Instance *instance = Instance::getInstance();

        instance->init();

        return EXIT_SUCCESS;
    } catch (const std::exception& ex) {
        waitUntilKeypress("Критична помилка: " + std::string(ex.what()));
        return EXIT_FAILURE;
    }
}