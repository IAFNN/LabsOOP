//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_NAMECOMPARATORMTV_H
#define LAB9OOP_NAMECOMPARATORMTV_H
#include "PriceComparatorMTV.h"
#include "IDComparatorMTV.h"
#include "ItemMTV.h"

class NameComparatorMTV : public PriceComparatorMTV, public IDComparatorMTV{
    int compare(ItemMTV* item1, ItemMTV* item2) override;

};


#endif //LAB9OOP_NAMECOMPARATORMTV_H
