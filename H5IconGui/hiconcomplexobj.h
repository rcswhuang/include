#ifndef HICONCOMPLEXOBJ_H
#define HICONCOMPLEXOBJ_H
#include "hicontemplate.h"
#include "hiconsymbol.h"
#include "hdynamicobj.h"
#include "hiconrectobj.h"
class HIconTemplate;
class HIconSymbol;
/***************************************图符**********************************/
class H5ICONGUI_EXPORT HIconComplexObj : public HRectObj //HSymbolGraphicsItem 图符类
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
    virtual void resetRectPoint(const QPointF& pt1,const QPointF& pt2);
public:
    void setUuid(const QString&);
    QString getUuid();

    void setCatalogName(const QString&);
    QString getCatalogName();
   // void setTopLeft(const QPointF& pointF);
   // QPointF getTopLeft();
   // void setRectWidth(double width);
   // double getRectWidth();
    //void setRectHeight(double height);
   // double getRectHeight();
    int getObjType(){return catalogType;}
    void initIconTemplate();
    void setIconTemplate(HIconTemplate* t);
    HIconTemplate* iconTemplate();
    HIconSymbol* getIconSymbol();
    HDynamicObj* getDynamicObj();
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
};

/*****************************遥测类**********************************/
class H5ICONGUI_EXPORT HAnalogueObj : public HIconComplexObj // 遥测类
{
public:
    HAnalogueObj();
    HAnalogueObj(HIconTemplate* it);
    virtual ~HAnalogueObj();
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


private:
    //遥测的属性
    ushort btFormat;//1，不带小数点；2，带1位小数点;3，带2位小数点;4，带3位小数点
    QString strPrefix; //前缀
    QString strSuffix; //后缀

};


#endif // HICONCOMPLEXOBJ_H
