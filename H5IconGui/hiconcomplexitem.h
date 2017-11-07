﻿#ifndef HICONCOMPLEXITEM_H
#define HICONCOMPLEXITEM_H
#include <QtGlobal>
#include "hiconapi.h"
#include "hicongraphicsitem.h"
class HBaseObj;
class HIconComplexObj;
class QObject;
class QRectF;
class QPainterPath;
class QPointF;
class QPainter;
class QStyleOptionGraphicsItem;
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class H5ICONGUI_EXPORT HIconComplexItem : public HIconGraphicsItem
{
public:
    enum {Type = enumComplex};

    HIconComplexItem(HIconGraphicsItem *parent = Q_NULLPTR);
    HIconComplexItem(const QRectF &rectF, HIconGraphicsItem *parent = Q_NULLPTR);
public:
    virtual void setRect(const QRectF& rect);
    virtual QRectF rect()const;
    void refreshBaseObj();
public:
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    virtual QPainterPath shape() const;
    virtual int type() const;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
public:
    virtual ushort pointInRect(QPointF& point);
    virtual void setItemCursor(int position);
    virtual HBaseObj* getItemObj();
    virtual void setItemObj(HBaseObj*);
    virtual void moveItemBy(qreal dx,qreal dy);
    virtual void resizeItem(const QPolygonF& polygonF);
public:
    QRectF rectF;
    HIconComplexObj* pIconComplxObj;
    ushort rectMode;
    ushort pointLocation;
    QPointF pointStart;
  //  bool bSelected;
};

#endif // HICONSYMBOLITEM_H
