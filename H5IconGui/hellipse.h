#ifndef HELLIPSE_H
#define HELLIPSE_H
#include "hrectangle.h"

class H5ICONGUI_EXPORT HEllipse : public HRectangle
{
public:
    friend class HRectangle;
    HEllipse();
    virtual ~HEllipse();

    //二进制读写
    //virtual void readData(QDataStream* data);
    //virtual void writeData(QDataStream* data);


    //xml文件读写
    //virtual void readXml(QDomElement* data);
    //virtual void writeXml(QDomElement* data);

    virtual QString TagName();
    //拷贝克隆
    virtual void copyTo(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    virtual void paint(QPainter* painter);

    virtual QRectF boundingRect();
    virtual bool contains(const QPointF &point);
    virtual QPainterPath shape();
    virtual QPainterPath getPath();//只提供矩形，圆，椭圆，文字三种支持图片
};
#endif // HELLIPSE_H
