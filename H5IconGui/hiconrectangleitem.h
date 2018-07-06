#ifndef HICONRECTANGLEITEM_H
#define HICONRECTANGLEITEM_H
#include <QtGlobal>
#include "hiconapi.h"
#include "hicongraphicsitem.h"
class HBaseObj;
class HRectangle;
class QPainterPath;
class QPainter;
class QStyleOptionGraphicsItem;
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class H5ICONGUI_EXPORT HIconRectangleItem : public HIconGraphicsItem
{
public:
    enum {Type = enumRectangle};

    HIconRectangleItem(HIconGraphicsItem *parent = Q_NULLPTR);
    HIconRectangleItem(HBaseObj* obj, HIconGraphicsItem *parent = Q_NULLPTR);
    virtual ~HIconRectangleItem();
public:
    virtual void setRect(const QRectF& rect);//no
    virtual QRectF rect() const; //no
    void refreshBaseObj(const QRectF& rect);//no
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
public:
    virtual ushort pointInRect(QPointF& point);//ok
    virtual void setItemCursor(int position);//ok
    virtual HBaseObj* getItemObj();
    virtual void setItemObj(HBaseObj*);
    virtual void moveItemBy(qreal dx,qreal dy);//ok
    virtual void resizeItem(const QPolygonF& polygonF);//ok
public:
    QRectF rectF;
    HRectangle* pRectObj;
    ushort rectMode;//ok
    ushort pointLocation;//ok
    QPointF pointStart;//ok
  //  bool bSelected;
};

#endif // HICONRECTITEM_H
