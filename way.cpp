#include "way.h"
#include <QPainter>
#include <QColor>

Way::Way(QPoint pos)
    : m_pos(pos)
    , m_nextWayPoint(NULL)
{
}

void Way::setNextWayPoint(Way *nextPoint)
{
    m_nextWayPoint = nextPoint;
}

Way* Way::nextWayPoint() const
{
    return m_nextWayPoint;
}

const QPoint Way::pos() const
{
    return m_pos;
}

void Way::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::green);
    painter->drawEllipse(m_pos, 6, 6);
    painter->drawEllipse(m_pos, 2, 2);

    if (m_nextWayPoint)
        painter->drawLine(m_pos, m_nextWayPoint->m_pos);
    painter->restore();
}
