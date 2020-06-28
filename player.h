#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class QMediaPlayer;

enum SoundType
{
    EnemyDestorySound		// 敌人消失时的声音
};

class Player : public QObject
{
public:
    explicit Player(QObject *parent = 0);

    void startBGM();
    void playSound(SoundType soundType);

private:
    QMediaPlayer *m_backgroundMusic; // 只用来播放背景音乐
};

#endif // PLAYER_H
