//
// Created by User on 09.04.2022.
//

#ifndef LAB5OOP_MAINWINDOW_H
#define LAB5OOP_MAINWINDOW_H

#include <QWidget>
#include "Polynom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private:
    Ui::MainWindow *ui;
    Polynom* polynom;
private slots:
    void enter();
    void display();
    void addPolynom();
    void substractPolynom();
    void multiply();
    void getCoefficent();
    void calculateRoots();
    void inverse();
    void isEven();
    void updateNumberOfInstances();
};


#endif //LAB5OOP_MAINWINDOW_H
