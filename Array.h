//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_ARRAY_H
#define LAB9OOP_ARRAY_H
#include "Item.h"
#include "Comparator.h"

class Array {
private:
    Item* array;
    int size;
public:
    int getSize();
    void setSize(int size);
    Item* getArray();
    void setArray(Item* array);
    void sort(Comparator& comparator);
    Array();
    Array(Item* array, int size);
    ~Array();
    void addElement(Item* item);

};


#endif //LAB9OOP_ARRAY_H
