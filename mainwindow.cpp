#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("window1");//设置窗口1标题
    //产生关联
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(condButtonPressed1()));//实现start按钮转换到window2
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(condButtonPressed2()));//实现setting按钮转换到window3
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::condButtonPressed1()
{
    view1=new MainWindow2(this);//将类指针实例化
    view1->show();
    this->hide();//将window1关闭
}

void MainWindow::condButtonPressed2()
{
    view2=new MainWindow3(this);
    view2->show();
}
