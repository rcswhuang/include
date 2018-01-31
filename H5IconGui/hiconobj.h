#ifndef HICONOBJ_H_
#define HICONOBJ_H_
#include "hbaseobj.h"

class H5ICONGUI_EXPORT HLineObj : public HBaseObj
{
public:
    HLineObj();
    virtual ~HLineObj();

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



//多边形
class H5ICONGUI_EXPORT HPolygonObj : public HBaseObj
{
public:
    HPolygonObj();
    virtual ~HPolygonObj();

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

//折线
class H5ICONGUI_EXPORT HPolylineObj : public HBaseObj
{
public:
    HPolylineObj();
    virtual ~HPolylineObj();

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





#endif // HLINEOBJ_H
