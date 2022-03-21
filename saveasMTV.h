//
// Created by User on 19.03.2022.
//

#ifndef LAB3OOP_SAVEASMTV_H
#define LAB3OOP_SAVEASMTV_H

#include <QWidget>
#include "notepadMTV.h"
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class saveAs; }
QT_END_NAMESPACE

class saveAs : public QDialog {
Q_OBJECT

public:
    explicit saveAs(QWidget *parent = nullptr, Notepad* creator = nullptr, bool isBeforeClosing = false);
    Notepad* creator;
    ~saveAs() override;
    std::string filepath;
    bool isBeforeClosing;
private slots:
    void save();
    void cancel();
private:
    Ui::saveAs *ui;
};


#endif //LAB3OOP_SAVEASMTV_H
