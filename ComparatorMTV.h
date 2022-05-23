//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_COMPARATORMTV_H
#define LAB9OOP_COMPARATORMTV_H
#include "ItemMTV.h"

class ComparatorMTV {
public:
    virtual int compare(ItemMTV* item1, ItemMTV* item2) = 0;
};


#endif //LAB9OOP_COMPARATORMTV_H
