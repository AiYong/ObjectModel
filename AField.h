#ifndef AFIELD_H
#define AFIELD_H

#include "AObject.h"
#include "AString.h"
#include "AModifier.h"


class AClass;
class AAnnotation;

class AField : public AObject
{
    A_OBJECT()
public:

    typedef AAnnotation* AnnotationIterator;

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
     * @brief IsArray
     * @return
     */
    virtual bool IsArray() const = 0;

public:

    /**
     * @brief GetModifiers
     * @return
     */
    virtual int GetModifiers() const = 0;


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
    virtual AnnotationIterator AnnotationBegin() = 0;

    /**
     * @brief AnnotationEnd
     * @return
     */
    virtual AnnotationIterator AnnotationEnd() = 0;


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
