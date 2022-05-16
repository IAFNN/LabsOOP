//
// Created by User on 01.05.2022.
//

#include "Item.h"

int Item::getID() {
    return id;
}

double Item::getPrice() {
    return price;
}

QString Item::getName() {
    return name;
}

void Item::setID(int id) {
    this->id = id;
}

void Item::setPrice(double price) {
    this->price = price;
}

void Item::setName(QString name) {
    this->name = name;
}
Item::Item(int id, double price, QString name) {
    this->id = id;
    this->price = price;
    this->name = name;
}