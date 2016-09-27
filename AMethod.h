#ifndef AMETHOD_H
#define AMETHOD_H

#include <initializer_list>

#include "AList.h"
#include "AString.h"

class AClass;
class AObject;
class AParameter;
class AAnnotation;


class AMethod
{
public:

    enum Access
    {
        Private,
        Protected,
        Public
    };

    enum MethodType
    {
        Method,
        Constructor,
        Destructor
    };

public:

    /**
     * @brief AMethod
     */
    AMethod();

    /**
     * @brief ~Method
     */
    virtual ~Method();

public:

    /**
     * @brief 返回方法名称
     * @return
     */
    AString const& GetName() const;

    /**
     * @brief 返回方法签名
     * @return
     */
    AString const& GetSignatrue() const;

    /**
     * @brief 返回返回值类型
     * @return
     */
    virtual AClass* GetReturnType() = 0;

    /**
     * @brief 返回参数
     * @return
     */
    virtual AList<AParameter*> const& GetParameters() = 0;

public:


    /**
     * @brief 返回方法的注解
     * @return
     */
    virtual AList<AAnnotation*> const& GetAnnotations() = 0;

public:

    /**
     * @brief 调用改方法
     * @param pObj
     * @param lParameters
     * @return
     */
    virtual AObject* Call(AObject const* pObj,std::initializer_list<AObject*> const& lParameters) = 0;

    /**
     * @brief IsEqual
     * @param pMethod
     * @return
     */
    virtual bool IsEqual(AMethod const* pMethod) = 0;

public:

    /**
     * @brief 测试方法是否为虚函数
     * @return
     */
    virtual bool IsVirtual() const = 0;

    /**
     * @brief 测试方法是否是const函数
     * @return
     */
    virtual bool IsConst() const = 0;

    /**
     * @brief 测试方法是否是静态函数
     * @return
     */
    virtual bool IsStatic() const;

    /**
     * @brief 测试方法是否已实现
     * @return
     */
    virtual bool IsImplement() const;

    /**
     * @brief 返回方法的访问属性
     * @return
     */
    virtual Access GetAccess() const = 0;

    /**
     * @brief 返回方法的类型
     * @return
     */
    virtual MethodType GetMethodType() const = 0;

};

#endif // AMETHOD_H
