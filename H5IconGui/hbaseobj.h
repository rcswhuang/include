﻿#ifndef HBASEOBJ_H
#define HBASEOBJ_H

#include <QObject>
#include <QColor>
#include <QVector>
#include <QDataStream>
#include <QDomElement>
#include <QPainterPath>
#include <QPainter>
#include "hiconapi.h"
#include "h5iconguiexport.h"
#include "hicongraphicsitem.h"
class H5ICONGUI_EXPORT HBaseObj: public QObject
{
public:
    HBaseObj(QObject *parent = 0);
    virtual ~HBaseObj();

public:
    void init();

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

    virtual void setObjName(const QString strName);
    virtual QString getObjName();
    //形状类型
    virtual DRAWSHAPE getShapeType();
    virtual void setShapeType(DRAWSHAPE t);

    //ObjID
    virtual int getObjID();
    virtual void setObjID(int nObjID);

    //线条颜色
    virtual void setLineColorName(QString clrName);
    virtual QString getLineColorName();

    //线宽
    virtual void setLineWidth(quint8 lineWidth);
    virtual quint8 getLineWidth();

    virtual void setLineStyle(Qt::PenStyle style);
    virtual Qt::PenStyle getLineStyle();

    //线连接处形状
    virtual void setLineJoinStyle(Qt::PenJoinStyle style);
    virtual Qt::PenJoinStyle getLineJoinStyle();

    //线端形状
    virtual void setLineCapStyle(Qt::PenCapStyle style);
    virtual Qt::PenCapStyle getLineCapStyle();

    //填充选择
    virtual void setFillWay(quint8 fillWay);
    virtual quint8 getFillWay();

    //填充方式(风格)
    virtual void setFillStyle(quint8 style);
    virtual quint8 getFillStyle();

    //填充色
    virtual void setFillColorName(QString clrName);
    virtual QString getFillColorName();

    //填充方向
    virtual void setFillDirection(quint8 fillDirection);
    virtual quint8 getFillDirection();

    //填充比例
    virtual void setFillPercentage(quint8 fillPer);
    virtual quint8 getFillPercentage();

    //边框可见
    virtual void setFrameSee(bool frameSee);
    virtual bool getFrameSee();

    //透明度
    virtual void setTransparency(quint8 transparency);
    virtual quint8 getTransparency();

    //边框色
    virtual void setBorderColor(const QColor* c);
    virtual QColor getBorderColor();

    //文字色
    virtual void setTextColor(const QColor* c);
    virtual QColor getTextColor();

    //矩形框的x,y轴弯曲度
    virtual void setRound(bool bcheck);
    virtual bool getRound();

    virtual void setXAxis(int xAxis);
    virtual int getXAxis();

    virtual void setYAxis(int yAxis);
    virtual int getYAxis();

    //是否旋转
    bool isRotated(qint8 nFlag);

    //旋转角度
    void setRotateAngle(float rotate);
    float getRotateAngle();

    //增加一个角度
    void setRotateAdd(float fAngle);

    //翻转
    bool isTurned(qint8 nFlag);

    //是否水平翻转
    bool isTurn(bool bHorizonTurn);

    //设置翻转
    void setTurn(bool bHorizon,bool bVertical);

    //是否可见
    virtual void setVisible(bool,int nFlag = 0);
    virtual bool isVisible();

    //是否删除
    virtual void setDeleted(bool bDel);
    virtual bool isDeleted();

    //叠放次序
    qint64 getStackOrder();
    virtual void setStackOrder(qint64 nStack);

    virtual void setOX(double x);
    virtual double getOX();
    virtual void setOY(double y);
    virtual double getOY();

    virtual void setModify(bool modify);
    virtual bool getModify();

    //当前画面的比例缩放
    double curZoomScale();

    bool contains(int nPatternId);

    virtual void moveBy(qreal dx,qreal dy);

    //设置item对象
    virtual void setIconGraphicsItem(HIconGraphicsItem* item);
    virtual HIconGraphicsItem* getIconGraphicsItem();

    //改变大写
    virtual void resize(double w,double h);
    virtual void setTopLeftPoint(const QPointF& point);

public:
    virtual void paint(QPainter* painter);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;

//绘制对象的属性
public:

    //基本信息
    QString strObjName; //对象名称

    quint8 drawShape;//图符类型(直线\圆)

    //对象标识ID
    quint32 nObjectId;

    double originX;//原点位置（x,y)
    double originY;

    //线条
    QString strLineColor;//线条颜色

    quint8 nLineWidth;//线宽

    quint8 nLineStyle;//线型

    quint8 nLineJoinStyle;//线连接处形状

    quint8 nLineCapStyle;//线端形状

    //填充方面
    quint8 nFillWay;//填充方式

    quint8 nFillStyle;//填充风格

    QString strFillColor; //填充颜色

    quint8 nFillDirection;//填充方向

    quint8 nFillPercentage;//填充比例

    //边框透明度
    bool bFrameSee;//边框可见

    quint8 nTransparency; //透明度

    //旋转
    float fRotateAngle;//旋转角度

    bool bHorizonTurn;//水平翻转

    bool bVerticalTurn;//垂直翻转

    bool bVisible;//是否显示

    bool bDeleted;//是否删除

    bool bRound;

    int nxAxis;//x轴弯曲度

    int nyAxis;//y轴

    qint64 nStackOrder;

    quint8 nPattern;

    bool bModify;
private:
    HIconGraphicsItem* pIconGraphicsItem;
protected:


    //父图符
    HBaseObj* m_pParent;

    //平面号
    QVector<qint8> m_nPlanes;

};


#endif // HBASEOBJ_H
