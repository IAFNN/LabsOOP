//
// Created by User on 01.05.2022.
//

#include "ArrayMTV.h"

ArrayMTV::ArrayMTV() {
    array = nullptr;
    size = 0;
}
ArrayMTV::ArrayMTV(ItemMTV *array, int size) {
    this->array = array;
    this->size = size;
}

ItemMTV *ArrayMTV::getArray() {
    return array;
}

void ArrayMTV::setArray(ItemMTV *array) {
    this->array = array;
}

int ArrayMTV::getSize() {
    return size;
}

void ArrayMTV::setSize(int size) {
    this->size = size;
}

void ArrayMTV::sort(ComparatorMTV &comparator) {
    for(int i = 0; i < size; i++){
        for(int i2 = 0; i2 < size - 1 - i; i2++){
            if(comparator.compare(&array[i2], &array[i2 + 1]) > 0){
                ItemMTV temp = array[i2 + 1];
                array[i2 + 1] = array[i2];
                array[i2] = temp;
            }
        }
    }
}
ArrayMTV::~ArrayMTV() {
    delete[] array;
}

void ArrayMTV::addElement(ItemMTV *item) {
    ItemMTV* newArray = new ItemMTV[++size];
    for(int i = 0; i < size - 1; i++){
        newArray[i] = array[i];
    }
    newArray[size - 1] = *item;
    array = newArray;
    return;
}