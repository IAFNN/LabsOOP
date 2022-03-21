//
// Created by User on 20.03.2022.
//

#ifndef LAB3OOP_OPENFILE_H
#define LAB3OOP_OPENFILE_H

#include <QWidget>
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class OpenFile; }
QT_END_NAMESPACE

class OpenFile : public QWidget {
Q_OBJECT

public:
    explicit OpenFile(QWidget *parent = nullptr, mainWindow* creator = nullptr);
    mainWindow* creator;
    ~OpenFile() override;
private slots:
    void open();
    void cancel();
private:
    Ui::OpenFile *ui;
};


#endif //LAB3OOP_OPENFILE_H
