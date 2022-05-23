//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_IDCOMPARATORMTV_H
#define LAB9OOP_IDCOMPARATORMTV_H
#include "ComparatorMTV.h"

class IDComparatorMTV : virtual public ComparatorMTV{
public:
    int compare(ItemMTV* item1, ItemMTV* item2) override;
};


#endif //LAB9OOP_IDCOMPARATORMTV_H
