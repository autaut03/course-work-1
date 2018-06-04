#include "DummyItem.h"

bool DummyItem::canBePointedAt() {
    return false;
}


std::string DummyItem::getDisplayString() {
    return msg_;
}

void DummyItem::process() {}

DummyItem::DummyItem() {}

DummyItem::DummyItem(std::string msg) : msg_(msg) {}
