#include <iostream>
#include "ExitOption.h"
#include "../Instance.h"

using namespace std;

string ExitOption::getDisplayName() {
    return "Вийти з програми";
}

void ExitOption::process() {
    Instance::getInstance()->exit();
}
