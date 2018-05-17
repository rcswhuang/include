#ifndef HICONSELECTIONITEM_H
#define HICONSELECTIONITEM_H

#include <QtGlobal>
#include "hicongraphicsitem.h"
#include "hiconapi.h"
//class QObject;
//class QRectF;
class QPainterPath;
//class QPointF;
class QPainter;
class QStyleOptionGraphicsItem;
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class H5ICONGUI_EXPORT HIconSelectionItem : public HIconGraphicsItem
{
public:
    enum {Type = enumSelection};

    HIconSelectionItem(HIconGraphicsItem *parent = Q_NULLPTR);
    HIconSelectionItem(const QRectF &rectF, HIconGraphicsItem *parent = Q_NULLPTR);
    ~HIconSelectionItem();
public:
    void setRect(const QRectF& rect);
    QRectF rect()const;
    void resetRectPoint(const QPointF& pt1,const QPointF& pt2);
    void resize(double w,double h);
    void moveBy(qreal dx,qreal dy);
public:
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    virtual QPainterPath shape() const;
    virtual int type() const;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);//ok?
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);//ok?
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);//ok
    virtual void keyPressEvent(QKeyEvent *event);//ok
    virtual ushort pointInRect(QPointF& point);
    virtual void setItemCursor(int position);

public:
    QRectF rectF;
    QPointF pointStart;
    ushort pointLocation;
    QList<HBaseObj*> pObjList;
  //  bool bSelected;
};

#endif // HICONSELECTIONITEM_H
