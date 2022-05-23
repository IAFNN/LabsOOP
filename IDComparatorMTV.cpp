//
// Created by User on 01.05.2022.
//

#include "IDComparatorMTV.h"

int IDComparatorMTV::compare(ItemMTV *item1, ItemMTV *item2) {
    return item1->getID() - item2->getID();
}