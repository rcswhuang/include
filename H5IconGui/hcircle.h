#ifndef HCIRCLE_H
#define HCIRCLE_H
#include "hellipse.h"
//圆形
class H5ICONGUI_EXPORT HCircle : public HEllipse
{
public:
    friend class HEllipse;
    HCircle();
    virtual ~HCircle();

    //二进制读写
    //virtual void readData(QDataStream* data);
    //virtual void writeData(QDataStream* data);


    //xml文件读写
    //virtual void readXml(QDomElement* data);
    //virtual void writeXml(QDomElement* data);

    virtual QString TagName();
    //拷贝克隆
    virtual void copyTo(HBaseObj* obj);
    //virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    //virtual void moveBy(qreal dx,qreal dy);
    virtual void paint(QPainter* painter);

    //virtual void resize(double w,double h);
    //virtual QRectF boundingRect() const;
    //virtual bool contains(const QPointF &point) const;
    //virtual QPainterPath shape() const;

};
#endif // HCIRCLE_H
