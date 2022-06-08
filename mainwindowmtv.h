//
// Created by User on 08.05.2022.
//

#ifndef LAB11OOP_MAINWINDOWMTV_H
#define LAB11OOP_MAINWINDOWMTV_H

#include <QWidget>
#include <stack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowMTV; }
QT_END_NAMESPACE

class MainWindowMTV : public QWidget {
Q_OBJECT

public:
    explicit MainWindowMTV(QWidget *parent = nullptr);

    ~MainWindowMTV() override;

private:
    Ui::MainWindowMTV *ui;
    std::vector<double> firstContainer;
    std::stack<double> secondContainer;
    std::vector<double> thirdContainer;
    void refreshFirstContainer();
    void sortVector(std::vector<double>& vector, bool increasingOrder);
    void refreshSecondContainer();
    void refreshSecondContainer(std::vector<double> copy);
private slots:
    void put();
    void edit();
    void deleteElement();
    void print();
    void step6();
    void sort();
    void find();
    void step13();
    void step15();
    void step17();
};


#endif //LAB11OOP_MAINWINDOWMTV_H
