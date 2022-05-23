//
// Created by User on 01.05.2022.
//

#include "NameComparatorMTV.h"


int NameComparatorMTV::compare(ItemMTV *item1, ItemMTV *item2) {
    int result = item1->getName().compare(item2->getName());;
    if(!result){
        return this->PriceComparatorMTV::compare(item1, item2);
    }else{
        return result;
    }
}