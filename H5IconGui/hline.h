#ifndef HLINE_H
#define HLINE_H
#include "hbaseobj.h"
class H5ICONGUI_EXPORT HLine : public HBaseObj
{
public:
    HLine();
    virtual ~HLine();

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
    virtual void paint(QPainter* painter);

    virtual void resize(double w,double h);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;
    virtual void resetRectPoint(const QPointF& pt1,const QPointF& pt2);


public:

    void setArrowStart(quint8 start);
    quint8 getArrowStart();

    void setArrowEnd(quint8 end);
    quint8 getArrowEnd();

    void setArrowWidth(quint16 width);
    quint16 getArrowWidth();

    void setArrowHeight(quint16 height);
    quint16 getArrowHeight();

    void setHeadPoint(QPointF pt){pfHeadPoint = pt;}
    void setTailPoint(QPointF pt){pfTailPoint = pt;}
    QPointF getHeadPoint(){return pfHeadPoint;}
    QPointF getTailPoint(){return pfTailPoint;}

private:
    bool bModify;
    quint8 arrowStart;//箭头的类型
    quint8 arrowEnd;//箭尾的类型
    double arrowWidth;
    double arrowHeight;
    QPointF ptOld,ptNew;
//public:
    QPointF pfHeadPoint;
    QPointF pfTailPoint;
};
#endif // HLINE_H
