#ifndef HICONRECTITEM_H
#define HICONRECTITEM_H
#include <QtGlobal>
#include "hiconapi.h"
#include "hicongraphicsitem.h"
class HBaseObj;
class HRectangle;
//class QObject;
//class QRectF;
class QPainterPath;
//class QPointF;
class QPainter;
class QStyleOptionGraphicsItem;
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class H5ICONGUI_EXPORT HIconRectItem : public HIconGraphicsItem
{
public:
    enum {Type = enumRectangle};

    HIconRectItem(HIconGraphicsItem *parent = Q_NULLPTR);
    HIconRectItem(const QRectF &rectF, HIconGraphicsItem *parent = Q_NULLPTR);
    virtual ~HIconRectItem();
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
