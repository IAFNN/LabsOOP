//
// Created by User on 01.05.2022.
//

#include "PriceComparatorMTV.h"

int PriceComparatorMTV::compare(ItemMTV *item1, ItemMTV *item2) {
    double result = item1->getPrice() - item2->getPrice();
    if(result == 0.0){
        return item1->getID() - item2->getID();
    }else{
        return result;
    }
}