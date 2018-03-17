#ifndef HICONOBJ_H
#define HICONOBJ_H
#include "hicontemplate.h"
#include "hiconsymbol.h"
#include "hdynamicobj.h"
#include "hrectangle.h"
class HIconTemplate;
class HIconSymbol;
/***************************************图符**********************************/
class H5ICONGUI_EXPORT HIconObj : public HRectangle //图符类
{
public:
    HIconObj();
    HIconObj(HIconTemplate* it);
    virtual ~HIconObj();
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

    void setObjType( uchar catalogType);
    int getObjType();

    void setSymbolName(const QString&);
    QString getSymbolName();

    void setSymbolType(int symbolType);
    int getSymbolType();

    void setGraphID(int graphID);
    int getGraphID();

    void setGraphOperator(uchar graphOperator);
    uchar getGraphOpeartor();

    void setGraphComfirm(uchar graphComfirm);
    uchar getGraphComfirm();

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
    QString strCatalogName;//目录名字
    int nCatalogType;//类型
    QString strUuid;//uuid

    //iconsymbol的信息
    QString strSymbolName;
    int nSymbolType;

    //画面ID
    int nGraphID;

    //画面操作方式
    uchar btGraphOperator;

    //画面确认方式
    uchar btGraphComfirm;
};

#endif // HICONOBJ_H
