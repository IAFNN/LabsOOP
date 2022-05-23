//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_ITEMMTV_H
#define LAB9OOP_ITEMMTV_H
#include <QString>

class ItemMTV {
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
    ItemMTV() = default;
    ItemMTV(int id, double price, QString name);
    ~ItemMTV() = default;
};


#endif //LAB9OOP_ITEMMTV_H
