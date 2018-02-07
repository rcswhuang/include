#ifndef HICONHELPER_H
#define HICONHELPER_H

#include "h5iconhelpexport.h"
#include <QPixmap>
#include <QString>
class HBaseObj;
//属性对话框信息要并入到IconHelp里面
class H5ICONHELP_EXPORT HIconHelper
{
public:
    HIconHelper();

public:
    static HIconHelper* m_pInstance;
    static HIconHelper* Instance();

public:
    QPixmap iconPixmap(const QString& strType,const QString& uuid);
    void setObjAttribute(HBaseObj* pObj);

};

#endif // HICONHELPER_H
