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
public:
    QPointF pfHeadPoint;
    QPointF pfTailPoint;
};

///////////////////////////////////////////HRectObj///////////////////////////////////////////
class H5ICONGUI_EXPORT HRectObj : public HBaseObj
{
public:
    HRectObj();
    virtual ~HRectObj();

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
public:
    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;
};


class H5ICONGUI_EXPORT HEllipseObj : public HBaseObj
{
public:
    HEllipseObj();
    virtual ~HEllipseObj();

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
public:
    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;
};

//圆形
class H5ICONGUI_EXPORT HCircleObj : public HBaseObj
{
public:
    HCircleObj();
    virtual ~HCircleObj();

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
public:
    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;
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
public:
   QVector<QPointF> pylist;
   qreal width;
   qreal height;
};

class H5ICONGUI_EXPORT HArcObj : public HBaseObj
{
public:
    HArcObj();
    virtual ~HArcObj();

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
public:
    void setStartAngle(int sAngle);
    int getStartAngle();
    void setSpanAngle(int spanangle);
    int getSpanAngle();
    void setCloseStatus(bool bcheck);
    bool getCloseStatus();
public:
    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;
    int startAngle;//其实角度
    int spanAngle;//旋转角度
    bool bCloseCheck;
};


class H5ICONGUI_EXPORT HPieObj : public HBaseObj
{
public:
    HPieObj();
    virtual ~HPieObj();

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
    virtual void paint(QPainter* painter);

    virtual void resize(double w,double h);
public:
    void setStartAngle(int sAngle);
    int getStartAngle();
    void setSpanAngle(int spanangle);
    int getSpanAngle();
    void setCloseStatus(bool bcheck);
    bool getCloseStatus();
public:
    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;
    int startAngle;//起始角度
    int spanAngle;//旋转角度
};

/////////////////////////////////////Text//////////////////////////////
class H5ICONGUI_EXPORT HTextObj : public HBaseObj
{
public:
    HTextObj();
    virtual ~HTextObj();
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
    virtual void paint(QPainter* painter);

    virtual void resize(double w,double h);
public:
    void setTopLeftPoint(QPointF topLeft);
    QPointF getTopLeftPoint();

    void setRectWidth(double width);
    double getRectWidth();

    void setRectHeight(double height);
    double getRectHeight();


    void setTextColorName(QString strClrName);
    QString getTextColorName();

    void setLayout(ushort layout);
    ushort getLayout();

    void setHorizontalAlign(int hAlign);
    int getHorizontalAlign();

    void setVerticalAlign(int vAlign);
    int getVerticalAlign();

    void setTextFontName(QString strFontName);
    QString getTextFontName();

    void setPointSize(int ptSize);
    int getPointSize();

    void setWeight(int weight);
    int getWeigth();

    void setItalic(bool bitalic);
    bool getItalic();

    void setTextContent(QString strContent);
    QString getTextContent();


private:
    //矩形范围
    QPointF topLeft;
    //QPointF rectTop;
    double rectWidth;
    double rectHeight;

    QString strTextContent;//文字
    //文字颜色,文字字体,水平对齐，垂直对齐,布局方式
    ushort layout;
    int horizontalAlign;
    int verticalAlign;
    QString textColorName;
    QString textFontName;
    int pointSize;//字体大小
    int weight;//粗体
    bool italic;//斜体
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
public:
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
    HIconTemplate* pIconTemplate;//模板信息
    HIconSymbol* pIconSymbol;//实际对象Icon信息
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
