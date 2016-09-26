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
     * @brief GetName
     * @return
     */
    AString const& GetName() const;

    /**
     * @brief GetReturnType
     * @return
     */
    virtual AClass* GetReturnType() = 0;

    /**
     * @brief GetParameters
     * @return
     */
    virtual AList<AParameter*> const& GetParameters() = 0;

    /**
     * @brief GetParameterTypes
     * @return
     */
    virtual AList<AClass*> const& GetParameterTypes() = 0;

    /**
     * @brief GetAnnotation
     * @param pClass
     * @return
     */
    AAnnotation* GetAnnotation(AClass const* pClass);

    /**
     * @brief GetAnnotations
     * @return
     */
    virtual AList<AAnnotation*> const& GetAnnotations() = 0;

public:

    /**
     * @brief Call
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
     * @brief IsAbstract
     * @return
     */
    virtual bool IsAbstract() const = 0;

    /**
     * @brief IsConst
     * @return
     */
    virtual bool IsConst() const = 0;

    /**
     * @brief IsStatic
     * @return
     */
    virtual bool IsStatic() const;

    /**
     * @brief GetAccess
     * @return
     */
    virtual Access GetAccess() const = 0;

    /**
     * @brief GetMethodType
     * @return
     */
    virtual MethodType GetMethodType() const = 0;

};

#endif // AMETHOD_H
