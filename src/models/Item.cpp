#include "Item.h"

template <>
string Model<Item>::getTableName() {
    return "items";
}