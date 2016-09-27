#ifndef AFIELD_H
#define AFIELD_H

#include "AList.h"
#include "AString.h"

class AClass;
class AObject;
class AAnnotation;

class AField
{
public:

    enum Access
    {
        Private,
        Protected,
        Public
    };


public:

    /**
     * @brief AField
     */
    AField();

    /**
     * @brief ~AField
     */
    virtual ~AField();

public:

    /**
     * @brief GetType
     * @return
     */
    virtual AClass* GetType() = 0;

    /**
     * @brief GetName
     * @return
     */
    virtual AString const& GetName() const = 0;

public:

    /**
     * @brief IsStatic
     * @return
     */
    virtual bool IsStatic() const = 0;

    /**
     * @brief IsArray
     * @return
     */
    virtual bool IsArray() const = 0;

public:

    /**
     * @brief GetAccess
     * @return
     */
    virtual Access GetAccess() const = 0;

    /**
     * @brief GetAnnotations
     * @return
     */
    virtual AList<AAnnotation*> const& GetAnnotations() const = 0;


public:

    /**
     * @brief GetValue
     * @param pObj
     * @return
     */
    virtual AObject* GetValue(AObject* pObj) = 0;

    /**
     * @brief SetValue
     * @param pTarget
     * @param pValue
     */
    virtual void SetValue(AObject* pTarget,AObject *pValue) = 0;

    /**
     * @brief GetValue
     * @param pObj
     * @param nIndex
     * @return
     */
    virtual AObject* GetValue(AObject* pObj,size_t nIndex) = 0;

    /**
     * @brief SetValue
     * @param pTarget
     * @param nIndex
     * @param pValue
     */
    virtual void SetValue(AObject *pTarget, size_t nIndex, AObject *pValue) = 0;

};

#endif // AFIELD_H
