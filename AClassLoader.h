#ifndef ACLASSLOADER_H
#define ACLASSLOADER_H

#include "AList.h"
#include "AString.h"


class AClass;

class AClassLoader
{
public:

    /**
     * @brief 加载指定名称的AClass
     * @param strName 类名称
     * @return
     */
    static AClass* LoadForName(AString const& strName );

    /**
     * @brief 加载所有AClass
     * @return
     */
    static AList<AClass*> LoadAll();

    /**
     * @brief 从指定路径加载AClass
     * @param strPath
     * @return
     */
    static AList<AClass*> LoadFrom(AString const& strPath);

};

#endif // ACLASSLOADER_H
