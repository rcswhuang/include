#ifndef HGROUPOBJ_H
#define HGROUPOBJ_H
#include "hbaseobj.h"
class HIconSymbol;
class HGraph;
class H5ICONGUI_EXPORT HGroupObj : public HBaseObj
{
public:
    HGroupObj();
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
    virtual QRectF boundingRect();
    virtual bool contains(const QPointF &point);
    virtual QPainterPath shape();

    virtual void resetRectPoint(const QPointF& pt1,const QPointF& pt2);
    virtual void setObjRect(const QRectF& rect);
    virtual QRectF getObjRect();
    virtual void setSubObjRect(qreal dx,qreal dy);
    virtual QPolygonF getRectLists();
    //setstackobj
    virtual void drawSelect(QPainter* painter);//单个选择
    virtual void drawMulSelect(QPainter* painter,bool benchmark); //多选择
public:
    HBaseObj* newObj(QString tagName);
    void setGraph(HGraph* graph);
    void clear();
    void setTopLeft(const QPointF &pointF);
    QPointF getTopLeft();
	
    void setGroupWidth(double width);
    double getGroupWidth();
    void setGroupHeight(double height);
    double getGroupHeight();

    void addObj(HBaseObj* pObj);
    void delObj(HBaseObj* pObj);
    bool isEmpty();
    HBaseObj* takeFirst();

private:
    HGraph* m_pGraph;
    QList<HBaseObj*> pObjList;
    QString m_strUuid;
private:
    QPointF topLeft;
    double rectWidth;
    double rectHeight;
};

#endif // HGROUPOBJ_H
