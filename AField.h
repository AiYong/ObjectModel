#ifndef AFIELD_H
#define AFIELD_H

#include "AList.h"

class AClass;
class AObject;
class AAnnotation;

class AField
{
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
    virtual AClass* GetType();

    /**
     * @brief GetAnnotations
     * @return
     */
    virtual AList<AAnnotation*> const& GetAnnotations() const = 0;

    /**
     * @brief IsStatic
     * @return
     */
    virtual bool IsStatic() const;

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


};

#endif // AFIELD_H
