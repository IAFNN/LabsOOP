//
// Created by User on 01.05.2022.
//

#include "IDComparator.h"

int IDComparator::compare(Item *item1, Item *item2) {
    return item1->getID() - item2->getID();
}