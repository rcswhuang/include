#ifndef HGROUPOBJ_H
#define HGROUPOBJ_H

#include "hbaseobj.h"
class HIconSymbol;
class H5ICONGUI_EXPORT HGroupObj : public HBaseObj
{
public:
    HGroupObj(HIconSymbol* symbol);
    ~HGroupObj();
public:

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
    virtual void resize(double w,double h);
    virtual void paint(QPainter* painter);
    virtual QRectF boundingRect() const;
    virtual bool contains(const QPointF &point) const;
    virtual QPainterPath shape() const;

	void resetRectPoint(qreal dx, qreal dy);
    virtual void setObjRect(const QRectF& rect);
    virtual QRectF getObjRect();
    virtual void setSubObjRect(qreal dx,qreal dy);
    void setTopLeft(const QPointF &pointF);
    QPointF getTopLeft();
	
    void setGroupWidth(double width);
    double getGroupWidth();
    void setGroupHeight(double height);
    double getGroupHeight();

    void addObj(HBaseObj* pObj);
    void delObj(HBaseObj* pObj);

private:
    HIconSymbol* pIconSymbol;
    QList<HBaseObj*> pObjList;
private:
    QPointF topLeft;
    double rectWidth;
    double rectHeight;
};

#endif // HGROUPOBJ_H
