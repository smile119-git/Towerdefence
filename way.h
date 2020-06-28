#ifndef WAY_H
#define WAY_H

#include <QPoint>

class QPainter;

// 敌人移动的航线
class Way
{
public:
    Way(QPoint pos);

    void setNextWayPoint(Way *nextPoint);
    Way* nextWayPoint() const;
    const QPoint pos() const;

    void draw(QPainter *painter) const;

private:
    const QPoint		m_pos;
    Way *			m_nextWayPoint;
};


#endif // WAY_H
