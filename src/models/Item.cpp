#include "Item.h"

template <>
string Model<Item>::getTableName() {
    return "items";
}

template <>
vector<string> Model<Item>::getRequiredFieldsList() {
    return {
            "title", "description"
    };
}