//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_IDCOMPARATOR_H
#define LAB9OOP_IDCOMPARATOR_H
#include "Comparator.h"

class IDComparator : public Comparator{
    int compare(Item* item1, Item* item2) override;
};


#endif //LAB9OOP_IDCOMPARATOR_H
