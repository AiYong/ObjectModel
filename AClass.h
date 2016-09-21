#ifndef ACLASS_H
#define ACLASS_H

#include "AList.h"

#include "AString.h"

#include "AField.h"
#include "AMethod.h"
#include "ADestructor.h"
#include "AConstructor.h"
#include "AAnnotation.h"


class AClass
{
public:

    static AClass* LoadForName(AString const& strName );

    static AList<AClass*> LoadAll();

    static AList<AClass*> LoadFrom(AString const& strPath);

public:

    AClass();

    ~AClass();

public:

    AString GetName() const;

    AString GetCanonicalName() const;

public:

    AField* GetField( AString const& strFieldName );

    AField const* GetField( AString const& strFieldName ) const;

    bool HasField( AString const& strFieldName ) const;

public:

    AMethod* GetMethod( AString const& strMethodName );

    AMethod const* GetMethod( AString const& strMethodName ) const;

    bool HasMethod( AString const& strMethodName ) const;

};

#endif // ACLASS_H
