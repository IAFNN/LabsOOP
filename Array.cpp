//
// Created by User on 01.05.2022.
//

#include "Array.h"

Array::Array() {
    array = nullptr;
    size = 0;
}
Array::Array(Item *array, int size) {
    this->array = array;
    this->size = size;
}

Item *Array::getArray() {
    return array;
}

void Array::setArray(Item *array) {
    this->array = array;
}

int Array::getSize() {
    return size;
}

void Array::setSize(int size) {
    this->size = size;
}

void Array::sort(Comparator &comparator) {
    for(int i = 0; i < size; i++){
        for(int i2 = 0; i2 < size - 1 - i; i2++){
            if(comparator.compare(&array[i2], &array[i2 + 1]) > 0){
                Item temp = array[i2 + 1];
                array[i2 + 1] = array[i2];
                array[i2] = temp;
            }
        }
    }
}
Array::~Array() {
    delete[] array;
}

void Array::addElement(Item *item) {
    Item* newArray = new Item[++size];
    for(int i = 0; i < size - 1; i++){
        newArray[i] = array[i];
    }
    newArray[size - 1] = *item;
    array = newArray;
    return;
}