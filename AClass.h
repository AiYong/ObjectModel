#ifndef ACLASS_H
#define ACLASS_H

#include "AList.h"
#include "AString.h"

class AField;
class AMethod;
class AParameter;
class AAnnotation;
class AClassLoader;

#include "AObject.h"

/**
 * @brief The AClass class
 */
class AClass : public AObject
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

    /**
     * @brief 返回类加载器
     * @return
     */
    static AClassLoader* GetClassLoader();

public:

    /**
     * @brief 返回类名称
     * @return
     */
    virtual AString const& GetName() = 0;

public:

    /**
     * @brief 返回父类的AClass
     * @return
     */
    virtual AList<AClass*> const& GetParentClass() const;

    /**
     * @brief 返回指定名称父类的AClass
     * @param strParentName
     * @return
     */
    virtual AClass* GetParentClass(AString const& strParentName) const;


public:

    /**
     * @brief 返回指定名称AField
     * @param strFieldName
     * @return
     */
    virtual AField* GetField( AString const& strFieldName ) = 0;

    /**
     * @brief
     * @return
     */
    virtual AList<AField*> GetFields() = 0;

    /**
     * @brief GetDeclaredField
     * @param strFiledName
     * @return
     */
    virtual AField* GetDeclaredField(AString const& strFiledName ) = 0;

    /**
     * @brief GetDeclaredFields
     * @return
     */
    virtual AList<AField*> const& GetDeclaredFields() = 0;


public:

    /**
     * @brief GetMethod
     * @param strMethodName
     * @return
     */
    virtual AMethod* GetMethod( AString const& strMethodName ) = 0 ;

    /**
     * @brief GetMethod
     * @param strMethodName
     * @param lParameters
     * @return
     */
    virtual AMethod* GetMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters) = 0;

    /**
     * @brief GetMethods
     * @return
     */
    virtual AList<AMethod*>& GetMethods() ;

    /**
     * @brief GetDeclaredMethod
     * @param strMethodName
     * @return
     */
    virtual AMethod* GetDeclaredMethod( AString const& strMethodName ) = 0;

    /**
     * @brief GetDeclaredMethod
     * @param strMethodName
     * @param lParameters
     * @return
     */
    virtual AMethod* GetDeclaredMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters) = 0;

    /**
     * @brief GetMethods
     * @return
     */
    virtual AList<AMethod*>& GetDeclaredMethods() = 0;

public:

    /**
     * @brief GetAnnotations
     * @return
     */
    AList<AAnnotation const*> GetAnnotations() ;

public:

    /**
     * @brief 测试类是不是虚的，具有虚函数的类时虚的
     * @return
     */
    virtual bool IsVirtual() const = 0;

    /**
     * @brief 测试类是不是纯虚类
     * @return
     */
    virtual bool IsPureVirtual() const = 0;

    /**
     * @brief 测试类是不是容器类
     * @return
     */
    virtual bool IsContainer() const = 0;

    /**
     * @brief 返回容器类的模板类型的AClass
     * @return
     */
    virtual AClass* GetComponentClass() = 0;

public:

    /**
     * @brief NewInstance
     * @return
     */
    virtual AObject* NewInstance() = 0;

    /**
     * @brief NewInstance
     * @param lParameters
     * @return
     */
    virtual AObject* NewInstance(std::initializer_list<AParameter*> const& lParameters) = 0;

    /**
     * @brief CopyInstance
     * @param pObject
     * @return
     */
    virtual AObject* CopyInstance(AObject const* pObject) = 0;

    /**
     * @brief DeleteInstance
     * @param pObject
     */
    virtual void DeleteInstance(AObject const* pObject) = 0;

    /**
     * @brief IsEqual
     * @param pl
     * @param pr
     * @return
     */
    virtual bool IsEqual(AObject const* pl,AObject const* pr) = 0;

};

#endif // ACLASS_H
