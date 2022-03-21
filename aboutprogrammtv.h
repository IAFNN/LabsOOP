//
// Created by User on 23.02.2022.
//

#ifndef LAB3OOP_ABOUTPROGRAMMTV_H
#define LAB3OOP_ABOUTPROGRAMMTV_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class AboutProgramMTV; }
QT_END_NAMESPACE

class AboutProgramMTV : public QMainWindow {
Q_OBJECT

public:
    explicit AboutProgramMTV(QWidget *parent = nullptr);

    ~AboutProgramMTV() override;

private:
    Ui::AboutProgramMTV *ui;
};


#endif //LAB3OOP_ABOUTPROGRAMMTV_H
