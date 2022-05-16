//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_COMPARATOR_H
#define LAB9OOP_COMPARATOR_H
#include "Item.h"

class Comparator {
public:
    virtual int compare(Item* item1, Item* item2) = 0;
};


#endif //LAB9OOP_COMPARATOR_H
