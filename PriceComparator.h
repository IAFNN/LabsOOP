//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_PRICECOMPARATOR_H
#define LAB9OOP_PRICECOMPARATOR_H
#include "Comparator.h"
#include "Item.h"


class PriceComparator : public Comparator{
    int compare(Item* item1, Item* item2) override;
};


#endif //LAB9OOP_PRICECOMPARATOR_H
