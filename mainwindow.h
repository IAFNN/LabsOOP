//
// Created by User on 20.03.2022.
//

#ifndef LAB3OOPGRAPHIC_MAINWINDOW_H
#define LAB3OOPGRAPHIC_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QWidget {
Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    void showOpened(std::string filepath);
    ~mainWindow() override;
    void saveToPath();
private:
    Ui::mainWindow *ui;
private slots:
    void open();
    void createSaveAsWindow();
};


#endif //LAB3OOPGRAPHIC_MAINWINDOW_H
