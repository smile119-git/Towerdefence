#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);

    this->setWindowTitle("window3");//设置窗口3标题
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(on_slider_valueChanged()));//实现speed的数值滚动槽数据变动联系
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));//实现back按钮回到window1
}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::on_slider_valueChanged(int value)
{
    ui->sBox->setValue(value);
}

void MainWindow3::on_pushButton_2_clicked()//关闭window3,回到winsow1
{
    emit sendsignal();
    this->hide();
}
