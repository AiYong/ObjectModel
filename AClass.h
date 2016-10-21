#ifndef ACLASS_H
#define ACLASS_H
#include "AString.h"
#include "AObject.h"


class AField;
class AMethod;
class AParameter;
class AAnnotation;
class AClassLoader;


/**
 * @brief The AClass class
 */
class AClass : public AObject
{
    A_OBJECT()
public:

    typedef AClass*             AClassIterator;
    typedef AField*             AFieldIterator;
    typedef AMethod*            AMethodIterator;
    typedef AAnnotation*        AAnnotationIterator;

    /**
     * @brief 加载指定名称的AClass
     * @param strName 类名称
     * @return
     */
    static AClass* LoadForName(AString const& strName );

    /**
     * @brief 返回类加载器
     * @return
     */
    static AClassLoader* GetClassLoader();

public:

    /**
     * @brief 返回类名称
     * 该名称不带命名空间
     * @return
     */
    virtual AString const& GetName() = 0;

    /**
     * @brief 返回类的限定名
     * 限定名称是指带命名空间的名称
     * @return
     */
    virtual AString const& GetCanoncalName() = 0;

public:

    /**
     * @brief 返回基类迭代器
     * @return
     */
    virtual AClassIterator BaseBegin() = 0;

    /**
     * @brief
     * @return
     */
    virtual AClassIterator BaseEnd() = 0;

public:

    /**
     * @brief 返回指定名称AField
     * @param strFieldName
     * @return
     */
    virtual AField* GetField( AString const& strFieldName ) = 0;

    /**
     * @brief FieldBegin
     * @return
     */
    virtual AFieldIterator FieldBegin() = 0;

    /**
     * @brief FieldEnd
     * @return
     */
    virtual AFieldIterator FieldEnd() = 0;

    /**
     * @brief GetDeclaredField
     * @param strFiledName
     * @return
     */
    virtual AField* GetDeclaredField(AString const& strFiledName ) = 0;

    /**
     * @brief DeclaredFieldBegin
     * @return
     */
    virtual AFieldIterator DeclaredFieldBegin() = 0;

    /**
     * @brief DeclaredFieldEnd
     * @return
     */
    virtual AFieldIterator DeclaredFieldEnd() = 0;


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
    virtual AMethod* GetMethod(AString const& strMethodName,std::initializer_list<AParameter*> lParameters) = 0;

    /**
     * @brief MethodBegin
     * @return
     */
    virtual AMethodIterator MethodBegin() = 0;

    /**
     * @brief MethodEnd
     * @return
     */
    virtual AMethodIterator MethodEnd() = 0;

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
     * @brief DeclaredMethodBegin
     * @return
     */
    virtual AMethodIterator DeclaredMethodBegin() = 0;

    /**
     * @brief DeclaredMethodEnd
     * @return
     */
    virtual AMethodIterator DeclaredMethodEnd() = 0;

public:

    /**
     * @brief GetAnnotation
     * @param pAnnotationClass
     * @return
     */
    virtual AAnnotation* GetAnnotation(AClass *pAnnotationClass) = 0;

    /**
     * @brief AnnotationBegin
     * @return
     */
    virtual AAnnotationIterator AnnotationBegin() = 0;

    /**
     * @brief AnnotationEnd
     * @return
     */
    virtual AAnnotationIterator AnnotationEnd() = 0;


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
