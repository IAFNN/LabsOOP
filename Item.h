//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_ITEM_H
#define LAB9OOP_ITEM_H
#include <QString>

class Item {
private:
    int id;
    double price;
    QString name;
public:
    int getID();
    double getPrice();
    QString getName();
    void setID(int id);
    void setPrice(double price);
    void setName(QString name);
    Item() = default;
    Item(int id, double price, QString name);
    ~Item() = default;
};


#endif //LAB9OOP_ITEM_H
