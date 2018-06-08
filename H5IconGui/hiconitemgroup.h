#ifndef HICONITEMGROUP_H
#define HICONITEMGROUP_H
#include <QtGlobal>
#include "hiconapi.h"
#include "hicongraphicsitem.h"
#include <QGraphicsItemGroup>
class HBaseObj;
class HGroupObj;
class QPainterPath;
class QPainter;
class QStyleOptionGraphicsItem;
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsItemGroup;
class H5ICONGUI_EXPORT HIconItemGroup : public HIconGraphicsItem
{
public:
    enum {Type = enumGroup};

    HIconItemGroup(HIconGraphicsItem *parent = Q_NULLPTR);
    HIconItemGroup(const QRectF &rectF, HIconGraphicsItem *parent = Q_NULLPTR);
    virtual ~HIconItemGroup();

    void addToGroup(HIconGraphicsItem* item);
    void removeFromGroup(HIconGraphicsItem *item);
public:
    virtual void setRect(const QRectF& rect);
    virtual QRectF rect() const;
    void refreshBaseObj(const QRectF& rect);

    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    virtual QPainterPath shape() const;
    virtual int type() const;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

    virtual ushort pointInRect(QPointF& point);
    virtual void setItemCursor(int position);
    virtual void setItemObj(HBaseObj*);
    virtual HBaseObj* getItemObj();
    virtual void moveItemBy(qreal dx,qreal dy);
    virtual void resizeItem(const QPolygonF& polygonF);

private:
    QRectF rectF;
    HGroupObj* pGroupObj;
    QGraphicsItemGroup* m_pGraphicsItemGroup;
    ushort pointLocation;
    QPointF pointStart;
};

#endif // HICONITEMGROUP_H
