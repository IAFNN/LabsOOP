
#ifndef LAB7OOP_MAINWINDOW_H
#define LAB7OOP_MAINWINDOW_H

#include <QWidget>
#include "String.h"

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
    String* string;
private slots:
    void getLineEdit();
    void getFromTable();
    void changeSlotInTable();
    void putInTable();
    void editInLineEdit();
    void saveLineEdit();
    void editInTextEdit();
    void saveTextEdit();
    void deleteSymbol();
    void replace();
    void sort();
    void insert();
    void changeSize();
    void concatenate();
    void isBigger();
    void isEqual();
};

#endif //LAB7OOP_MAINWINDOW_H
