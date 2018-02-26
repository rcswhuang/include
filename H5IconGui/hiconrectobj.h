#ifndef HRECTOBJ_H
#define HRECTOBJ_H

#include "hbaseobj.h"

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
    virtual void resize(double w,double h);
    virtual void paint(QPainter* painter);
    virtual void setPainter(QPainter* painter,const QRectF& rect);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;
    virtual void resetRectPoint(const QPointF& pt1,const QPointF& pt2);
    virtual void setObjRect(const QRectF& rect);
    virtual QRectF getObjRect();

    virtual void setTopLeft(const QPointF& point);
    virtual QPointF getTopLeft();
    virtual void setRectWidth(double width);
    virtual double getRectWidth();
    virtual void setRectHeight(double height);
    virtual double getRectHeight();



public:
    QPointF ptOld,ptNew;
protected:
    QPointF topLeft;
    double rectWidth;
    double rectHeight;
};


class H5ICONGUI_EXPORT HEllipseObj : public HRectObj
{
public:
    friend class HRectObj;
    HEllipseObj();
    virtual ~HEllipseObj();

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

//圆形
class H5ICONGUI_EXPORT HCircleObj : public HRectObj
{
public:
    friend class HRectObj;
    HCircleObj();
    virtual ~HCircleObj();

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

class H5ICONGUI_EXPORT HArcObj : public HRectObj
{
public:
    friend class HRectObj;
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
    //virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    //virtual void moveBy(qreal dx,qreal dy);
    virtual void paint(QPainter* painter);

    //virtual void resize(double w,double h);
    //virtual QRectF boundingRect() const;
    //virtual bool contains(const QPointF &point) const;
    //virtual QPainterPath shape() const;

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


class H5ICONGUI_EXPORT HPieObj : public HRectObj
{
public:
    friend class HRectObj;
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
    //virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();
    //virtual void moveBy(qreal dx,qreal dy);
    virtual void paint(QPainter* painter);

    //virtual void resize(double w,double h);
    //virtual QRectF boundingRect() const;
    //virtual bool contains(const QPointF &point) const;
    //virtual QPainterPath shape() const;

public:
    void setStartAngle(int sAngle);
    int getStartAngle();
    void setSpanAngle(int spanangle);
    int getSpanAngle();
    //void setCloseStatus(bool bcheck);
    //bool getCloseStatus();
private:
    int startAngle;//起始角度
    int spanAngle;//旋转角度
};

/////////////////////////////////////Text//////////////////////////////
class H5ICONGUI_EXPORT HTextObj : public HRectObj
{
public:
    friend class HRectObj;
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
    //virtual void clone(HBaseObj* obj);

    virtual DRAWSHAPE getShapeType();

    //virtual void moveBy(qreal dx,qreal dy);
    virtual void paint(QPainter* painter);

    //virtual void resize(double w,double h);
    //virtual QRectF boundingRect() const;
    //virtual bool contains(const QPointF &point) const;
    //virtual QPainterPath shape() const;

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

    void setTextFormat(uchar btType);
    uchar getTextFormat();

    void setTextPrefix(const QString& strPrefix);
    QString getTextPrefix();

    void setTextSuffix(const QString& strSuffix);
    QString getTextSuffix();

private:
    QString strTextContent;//文字
    //文字颜色,文字字体,水平对齐，垂直对齐,布局方式
    ushort layout;
    int horizontalAlign;
    int verticalAlign;
    QString strPrefix;//前缀
    QString strSuffix;//后缀
    uchar    btFormat;//格式

    QString textColorName;
    QString textFontName;
    int pointSize;//字体大小
    int weight;//粗体
    bool italic;//斜体
};





#endif // HRECTOBJ_H
