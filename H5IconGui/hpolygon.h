#ifndef HPOLYGON_H
#define HPOLYGON_H
#include "hbaseobj.h"
//多边形
class H5ICONGUI_EXPORT HPolygon : public HBaseObj
{
public:
    HPolygon();
    virtual ~HPolygon();

    //二进制读写
    virtual void readData(QDataStream* data);
    virtual void writeData(QDataStream* data);

    //xml文件读写
    virtual void readXml(QDomElement* dom);
    virtual void writeXml(QDomElement* dom);

    virtual QString TagName();
    //拷贝克隆
    virtual void copyTo(HBaseObj* obj);
    virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    virtual void moveBy(qreal dx,qreal dy);
    virtual void paint(QPainter* painter);

    virtual void resize(double w,double h);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;
    virtual void resetRectPoint(const QPointF& pt1,const QPointF& pt2);

public:
   QVector<QPointF> pylist;
   qreal width;
   qreal height;
   QPointF ptOld,ptNew;
};
#endif // HPOLYGON_H
