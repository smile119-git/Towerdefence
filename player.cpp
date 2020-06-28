#include "player.h"
#include <QDir>
#include <QMediaPlay>
#include <QMediaPlaylist>


Player::Player(QObject *parent)
    : QObject(parent)
    , m_backgroundMusic(NULL)
{
    // 创建一直播放的背景音乐
    QUrl backgroundMusicUrl = QUrl::fromLocalFile(s_curDir + ":/image/hdl.mp3");
    if (QFile::exists(backgroundMusicUrl.toLocalFile()))
    {
        m_backgroundMusic = new QMediaPlayer(this);
        QMediaPlaylist *backgroundMusicList = new QMediaPlaylist();

        QMediaContent media(backgroundMusicUrl);
        backgroundMusicList->addMedia(media);
        backgroundMusicList->setCurrentIndex(0);
        // 设置背景音乐循环播放
        backgroundMusicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        m_backgroundMusic->setPlaylist(backgroundMusicList);
    }
}

void Player::startBGM()
{
    if (m_backgroundMusic)
        m_backgroundMusic->play();
}

void Player::playSound(SoundType soundType)
{
    static const QUrl mediasUrls[] =
    {
        QUrl::fromLocalFile(s_curDir + ":/image/crash.mp3")
    };
    static QMediaPlayer player;

    if (QFile::exists(mediasUrls[soundType].toLocalFile()))
    {
        player.setMedia(mediasUrls[soundType]);
        player.play();
    };
}
