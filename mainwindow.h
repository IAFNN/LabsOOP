//
// Created by User on 11.05.2022.
//

#ifndef LAB12OOP_MAINWINDOW_H
#define LAB12OOP_MAINWINDOW_H

#include <QWidget>
#include "Expression.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Expression* expression;
    Ui::MainWindow *ui;
private slots:
    void setN();
    void setM();
    void setK();
    void setX();
    void setNVector();
    void setMVector();
    void setKVector();
    void calculate();
};


#endif //LAB12OOP_MAINWINDOW_H
