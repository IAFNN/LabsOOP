//
// Created by User on 01.05.2022.
//

#ifndef LAB9OOP_MAINWINDOW_H
#define LAB9OOP_MAINWINDOW_H

#include <QWidget>
#include "ArrayMTV.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindowMTV : public QWidget {
Q_OBJECT

public:
    explicit MainWindowMTV(QWidget *parent = nullptr);
    ArrayMTV* array;
    ~MainWindowMTV() override;

private:
    void updateData();
    Ui::MainWindow *ui;
    int idOfLastElement = 0;
private slots:
    void addElement();
    void sortId();
    void sortName();
    void sortPrice();
};


#endif //LAB9OOP_MAINWINDOW_H
