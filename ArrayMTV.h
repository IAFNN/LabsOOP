//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_ARRAYMTV_H
#define LAB9OOP_ARRAYMTV_H
#include "ItemMTV.h"
#include "ComparatorMTV.h"

class ArrayMTV {
private:
    ItemMTV* array;
    int size;
public:
    int getSize();
    void setSize(int size);
    ItemMTV* getArray();
    void setArray(ItemMTV* array);
    void sort(ComparatorMTV& comparator);
    ArrayMTV();
    ArrayMTV(ItemMTV* array, int size);
    ~ArrayMTV();
    void addElement(ItemMTV* item);

};


#endif //LAB9OOP_ARRAYMTV_H
