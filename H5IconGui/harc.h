#ifndef HARC_H
#define HARC_H
#include "hrectangle.h"
class H5ICONGUI_EXPORT HArc : public HRectangle
{
public:
    friend class HRectangle;
    HArc();
    virtual ~HArc();

    //二进制读写
    virtual void readData(QDataStream* data);
    virtual void writeData(QDataStream* data);


    //xml文件读写
    virtual void readXml(QDomElement* data);
    virtual void writeXml(QDomElement* data);

    virtual QString TagName();

    //拷贝克隆
    virtual void copyTo(HBaseObj* obj);
    //virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    //virtual void moveBy(qreal dx,qreal dy);
    virtual void paint(QPainter* painter);

    //virtual void resize(double w,double h);
    virtual QRectF boundingRect() ;
    virtual bool contains(const QPointF &point);
    virtual QPainterPath shape();

public:
    void setStartAngle(int sAngle);
    int getStartAngle();
    void setSpanAngle(int spanangle);
    int getSpanAngle();
    void setCloseStatus(bool bcheck);
    bool getCloseStatus();
private:
    int startAngle;//其实角度
    int spanAngle;//旋转角度
    bool bCloseCheck;
};
#endif // HARC_H
