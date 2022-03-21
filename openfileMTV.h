//
// Created by User on 20.03.2022.
//

#ifndef LAB3OOP_OPENFILEMTV_H
#define LAB3OOP_OPENFILEMTV_H

#include <QWidget>
#include "notepadMTV.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class OpenFile; }
QT_END_NAMESPACE

class OpenFile : public QDialog {
Q_OBJECT

public:
    explicit OpenFile(QWidget *parent = nullptr, Notepad* creator = nullptr);
    Notepad* creator;
    ~OpenFile() override;
private slots:
    void open();
    void cancel();
private:
    Ui::OpenFile *ui;
};


#endif //LAB3OOP_OPENFILEMTV_H
