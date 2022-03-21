//
// Created by User on 19.03.2022.
//

#ifndef LAB3OOP_CLOSEFILEMTV_H
#define LAB3OOP_CLOSEFILEMTV_H

#include <QWidget>
#include "notepadMTV.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class closeFile; }
QT_END_NAMESPACE

class closeFile : public QDialog {
Q_OBJECT

public:
    explicit closeFile(QWidget *parent = nullptr, Notepad* sender = nullptr, bool isBeforeClosing = true);
    ~closeFile() override;
    Notepad* sender;
    bool isBeforeClosing;
    QString previousText;
private slots:
    void save();
    void notSave();
private:
    Ui::closeFile *ui;
};


#endif //LAB3OOP_CLOSEFILEMTV_H
