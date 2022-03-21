//
// Created by User on 19.03.2022.
//

#ifndef LAB3OOP_CLOSEEVENTFILTERMTV_H
#define LAB3OOP_CLOSEEVENTFILTERMTV_H
#include <QObject>

class CloseEventFilterMTV : public QObject {
Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};


#endif //LAB3OOP_CLOSEEVENTFILTERMTV_H
