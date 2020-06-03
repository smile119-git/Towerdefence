#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    this->setWindowTitle("window2");//设置窗口2标题
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
