#ifndef HGROUPOBJ_H
#define HGROUPOBJ_H

#include "hbaseobj.h"
class H5ICONGUI_EXPORT HGroupObj : public HBaseObj
{
public:
    HGroupObj();
    ~HGroupObj();
public:

    //二进制读写
    virtual void readData(QDataStream* data);
    virtual void writeData(QDataStream* data);

    //xml文件读写
    virtual void readXml(QDomElement* data);
    virtual void writeXml(QDomElement* data);

    virtual QString TagName();

    //拷贝克隆
    virtual void copyTo(HBaseObj* obj);
    virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    virtual void moveBy(qreal dx,qreal dy);
    virtual void resize(double w,double h);
    virtual void paint(QPainter* painter);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;

public:
    QPointF topLeft;
    double rectWidth;
    double rectHeight;
};

#endif // HGROUPOBJ_H
