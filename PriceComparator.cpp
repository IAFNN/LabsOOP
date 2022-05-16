//
// Created by User on 01.05.2022.
//

#include "PriceComparator.h"

int PriceComparator::compare(Item *item1, Item *item2) {
    double result = item1->getPrice() - item2->getPrice();
    if(result == 0.0){
        result = item1->getName().compare(item2->getName());
        if(result == 0.0){
            return item1->getID() - item2->getID();
        }else{
            return result;
        }
    }else{
        return result;
    }
}