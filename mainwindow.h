//
// Created by User on 04.05.2022.
//

#ifndef LAB10OOP_MAINWINDOW_H
#define LAB10OOP_MAINWINDOW_H

#include <QWidget>
#include "NumberController.h"
#include "Fraction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    NumberController<Fraction>* numberController;
    Ui::MainWindow *ui;
private slots:
    void enter();
    void add();
    void subtract();
    void multiply();
    void divide();
};


#endif //LAB10OOP_MAINWINDOW_H
