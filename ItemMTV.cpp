//
// Created by User on 01.05.2022.
//

#include "ItemMTV.h"

int ItemMTV::getID() {
    return id;
}

double ItemMTV::getPrice() {
    return price;
}

QString ItemMTV::getName() {
    return name;
}

void ItemMTV::setID(int id) {
    this->id = id;
}

void ItemMTV::setPrice(double price) {
    this->price = price;
}

void ItemMTV::setName(QString name) {
    this->name = name;
}
ItemMTV::ItemMTV(int id, double price, QString name) {
    this->id = id;
    this->price = price;
    this->name = name;
}