#ifndef ACLASSCLASS_H
#define ACLASSCLASS_H

#include "../AClass.h"

class AClassClass : public AClass
{
public:

    virtual AString const& GetName();

public:

    virtual AList<AClass*> const& GetParentTypes();

    virtual AClass* GetParentType(AString const& strParentName) ;

public:

    virtual AField* GetField( AString const& strFieldName );

    virtual AList<AField*> GetFields();

    virtual AField* GetDeclaredField(AString const& strFiledName );

    virtual AList<AField*> const& GetDeclaredFields();

public:

    virtual AMethod* GetMethod( AString const& strMethodName ) ;

    virtual AMethod* GetMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters);

    virtual AList<AMethod*>& GetMethods();

    virtual AMethod* GetDeclaredMethod( AString const& strMethodName );

    virtual AMethod* GetDeclaredMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters);

    virtual AList<AMethod*>& GetDeclaredMethods();

public:

    AList<AAnnotation const*> GetAnnotations() ;

public:

    virtual bool IsAbstract() const;

public:


    virtual AObject* NewInstance();

    virtual AObject* NewInstance(std::initializer_list<AParameter*> const& lParameters);

    virtual AObject* CopyInstance(AObject const* pObject);

    virtual void DeleteInstance(AObject const* pObject);

    virtual bool IsEqual(AObject const* pl,AObject const* pr);
};

#endif // ACLASSCLASS_H
