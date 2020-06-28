#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "way.h"
#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include <QPainter>
#include <QMessageBox>
#include <QTimer>

using namespace std;

static const int TowerCost = 300;
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    this->setWindowTitle("window2");//设置窗口2标题

    /////////////
    preLoadWavesInfo();
    loadTowerPositions();
    addWayPoints();

    m_audioPlayer = new AudioPlayer(this);
    m_audioPlayer->startBGM();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
    timer->start(30);

    // 设置300ms后游戏启动
    QTimer::singleShot(300, this, SLOT(gameStart()));
}


MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pushButton_clicked()
{
    this->close();
}

///////

bool MainWindow2::Tower() const
{
    if (m_playrGold >= TowerCost)
        return true;
    return false;
}

void MainWindow2::drawWave(QPainter *painter)
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(400, 5, 100, 25), QString("WAVE : %1").arg(m_waves + 1));
}

Player *MainWindow2::Player() const
{
    return m_audioPlayer;
}

void MainWindow2::removedEnemy(Enemy *enemy)//移除敌人消失
{
    Q_ASSERT(enemy);

    m_enemyList.removeOne(enemy);
    delete enemy;
}

void MainWindow2::removedBullet(Bullet *bullet)//子弹消失
{
    Q_ASSERT(bullet);

    m_bulletList.removeOne(bullet);
    delete bullet;
}

void MainWindow2::addBullet(Bullet *bullet)//添加子弹
{
    Q_ASSERT(bullet);

    m_bulletList.push_back(bullet);
}
