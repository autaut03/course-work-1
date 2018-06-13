#ifndef KURSACH_ITEM_H
#define KURSACH_ITEM_H


#include "../orm/Model.hpp"

class Item: public Model<Item> {
    using Model<Item>::Model;
};


#endif //KURSACH_ITEM_H
