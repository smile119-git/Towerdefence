#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);

    this->setWindowTitle("window3");//设置窗口3标题
}

MainWindow3::~MainWindow3()
{
    delete ui;
}
