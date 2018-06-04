#include "Option.h"

bool Option::canBePointedAt() {
    return true;
}

std::string Option::getDisplayString() {
    return getDisplayName();
}
