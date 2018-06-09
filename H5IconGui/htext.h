#ifndef HTEXT_H
#define HTEXT_H
#include "hrectangle.h"
/////////////////////////////////////Text//////////////////////////////
class H5ICONGUI_EXPORT HText : public HRectangle
{
public:
    HText();
    virtual ~HText();
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
    virtual QRectF boundingRect();
    virtual bool contains(const QPointF &point) ;
    virtual QPainterPath shape();

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

#endif // HTEXT_H
