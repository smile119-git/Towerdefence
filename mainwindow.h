#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mainwindow2.h"
#include"mainwindow3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void condButtonPressed1();
    void condButtonPressed2();

private:
    Ui::MainWindow *ui;
    MainWindow2 *view1;//创建类的指针
    MainWindow3 *view2;
};
#endif // MAINWINDOW_H
