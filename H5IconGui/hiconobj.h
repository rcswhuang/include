#ifndef HICONOBJ_H_
#define HICONOBJ_H_
#include "hbaseobj.h"
#include "hicontemplate.h"
#include "hiconsymbol.h"
#include "hdynamicobj.h"
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

private:
    bool bModify;
    quint8 arrowStart;//箭头的类型
    quint8 arrowEnd;//箭尾的类型
    double arrowWidth;
    double arrowHeight;
    QPointF ptOld,ptNew;
public:
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

public:
   QVector<QPointF> pylist;
   qreal width;
   qreal height;
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

public:
   QVector<QPointF> pylist;
   qreal width;
   qreal height;
};


/***************************************图符**********************************/
class H5ICONGUI_EXPORT HIconComplexObj : public HBaseObj //HSymbolGraphicsItem 图符类
{
public:
    HIconComplexObj();
    HIconComplexObj(HIconTemplate* it);
    virtual ~HIconComplexObj();
public:
    /*
     * 存储分为两个部分
*/
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
    virtual void resize(qreal w,qreal h);
    virtual void paint(QPainter* painter);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;
public:
    void setUuid(const QString&);
    QString getUuid();

    void setTopLeft(const QPointF& pointF);
    QPointF getTopLeft();
    void setRectWidth(double width);
    double getRectWidth();
    void setRectHeight(double height);
    double getRectHeight();
    void initIconTemplate();
    void setIconTemplate(HIconTemplate* t);
    HIconTemplate* iconTemplate();
    HIconSymbol* getIconSymbol();
    void initDynamicData();
    void clearDynamicData();

protected:
    //模板主要是引用其他对象，或者拷贝过来
    HIconTemplate* pIconTemplate;//模板信息

    //将模板里iconsymbol对象的内容拷贝过来
    HIconSymbol* pIconSymbol;//实际对象Icon信息

    //动态信息
    HDynamicObj* pDynamicObj;//实际对象动态信息

    //每一个组合图元都是RectItem
    //icontemplate的信息
    QString catalogName;//目录名字
    int catalogType;//类型
    QString uuid;//uuid

    //iconsymbol的信息
    QString symbolName;
    int symbolType;

    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;
};



#endif // HLINEOBJ_H
