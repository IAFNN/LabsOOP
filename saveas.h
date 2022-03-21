//
// Created by User on 19.03.2022.
//

#ifndef LAB3OOP_SAVEAS_H
#define LAB3OOP_SAVEAS_H

#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class saveAs; }
QT_END_NAMESPACE

class saveAs : public QWidget {
Q_OBJECT

public:
    explicit saveAs(QWidget *parent = nullptr, mainWindow* creator = nullptr);
    mainWindow* creator;
    ~saveAs() override;
    std::string filepath;
private slots:
    void save();
    void cancel();
private:
    Ui::saveAs *ui;
};


#endif //LAB3OOP_SAVEAS_H
