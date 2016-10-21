#ifndef AMETHOD_H
#define AMETHOD_H

#include <initializer_list>

#include "AList.h"
#include "AString.h"

#include "AModifier.h"

class AClass;
class AObject;
class AParameter;
class AAnnotation;


class AMethod
{
public:

    enum MethodType
    {
        Method,
        Constructor,
        Destructor
    };

    typedef AParameter*  AParameterIterator;
    typedef AAnnotation* AAnnotationIterator;

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
    AString GetName() const = 0;

    /**
     * @brief 返回方法签名
     * @return
     */
    AString GetSignatrue() const = 0;

    /**
     * @brief 返回返回值类型
     * @return
     */
    virtual AClass* GetReturnType() const = 0;

    /**
     * @brief GetParameterCount
     * @return
     */
    virtual size_t GetParameterCount() const = 0;

    /**
     * @brief ParameterBegin
     * @return
     */
    virtual AParameterIterator ParameterBegin() const = 0;

    /**
     * @brief ParameterEnd
     * @return
     */
    virtual AParameterIterator ParameterEnd() const = 0;


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
     * @brief Call
     * @param pObj
     * @return
     */
    virtual AObject* Call(AObject *pObj,...) = 0;

public:

    /**
     * @brief 返回方法的访问属性
     * @return
     */
    virtual int GetModifiers() const = 0;

    /**
     * @brief 返回方法的类型
     * @return
     */
    virtual MethodType GetMethodType() const = 0;

};

#endif // AMETHOD_H
