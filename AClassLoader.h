#ifndef ACLASSLOADER_H
#define ACLASSLOADER_H

#include "AList.h"
#include "AString.h"

#include <vector>


class AClass;

/**
 * @brief The AClassLoadListener class
 */
class AClassLoadListener
{
public:

    typedef AClass* AClassIterator;

    virtual ~AClassLoadListener()
    {
    }

    virtual void Loaded(AClassIterator iFirst,AClassIterator iLast) = 0;
};


/**
 * @brief 类加载器
 * 类加载用于加载反射AClass
 */
class AClassLoader
{
public:

    /**
     * @brief 获取类加载器唯一实例
     * @return
     */
    static AClassLoader* GetInstance();

public:

    typedef AClass* AClassIterator;

    /**
     * @brief 加载指定名称的AClass
     * @param strName 类名称
     * @return
     */
    AClass* LoadForName(AString const& strName );

    /**
     * @brief 加载所有AClass
     * @return
     */
    bool LoadAll();

    /**
     * @brief 从指定路径加载AClass
     * @param strPath
     * @return
     */
    bool LoadFrom(AString const& strPath);

    /**
     * @brief ClassBegin
     * @return
     */
    AClassIterator ClassBegin() ;

    /**
     * @brief ClassEnd
     * @return
     */
    AClassIterator ClassEnd();

    /**
     * @brief RegisterLoadListener
     * @param pListener
     */
    void RegisterLoadListener(AClassLoadListener *pListener);

    /**
     * @brief UnRegisterLoadListener
     * @param pListener
     */
    void UnRegisterLoadListener(AClassLoadListener *pListener);

private:

    AClassLoader();
    ~AClassLoader();

    class Impl;
    Impl *pImpl;

};

#endif // ACLASSLOADER_H
