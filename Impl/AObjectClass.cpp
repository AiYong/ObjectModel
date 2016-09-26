#include "AObjectClass.h"

AString const& AObjectClass::GetName()
{
    return AString::FromLocaleString("AObject");
}

AList<AClass*> const& AObjectClass::GetParentTypes()
{
    return AList<AClass*>();
}

AClass* AObjectClass::GetParentType(AString const& strParentName)
{
    return nullptr;
}

AField* AObjectClass::GetField( AString const& strFieldName )
{
    UnUsed(strFieldName);
    return nullptr;
}

AList<AField*> AObjectClass::GetFields()
{
    return AList<AField*>();
}

AField* AObjectClass::GetDeclaredField(AString const& strFiledName)
{
    UnUsed(strFieldName);
    return nullptr;
}

AList<AField*> const& AObjectClass::GetDeclaredFields()
{
    UnUsed(strFieldName);
    return nullptr;
}

AMethod* AObjectClass::GetMethod( AString const& strMethodName )
{

}

AMethod* AObjectClass::GetMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters)
{

}

AList<AMethod*>& AObjectClass::GetMethods()
{

}

AMethod* AObjectClass::GetDeclaredMethod( AString const& strMethodName )
{

}

AMethod* AObjectClass::GetDeclaredMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters)
{

}

AList<AMethod*>& AObjectClass::GetDeclaredMethods()
{

}

AList<AAnnotation const*> AObjectClass::GetAnnotations()
{
    return AList<AAnnotation const*>();
}

bool AObjectClass::IsAbstract() const
{

}

AObject* AObjectClass::NewInstance()
{

}

AObject* AObjectClass::NewInstance(std::initializer_list<AParameter*> const& lParameters)
{

}

AObject* AObjectClass::CopyInstance(AObject const* pObject)
{

}

void AObjectClass::DeleteInstance(AObject const* pObject)
{

}

bool AObjectClass::IsEqual(AObject const* pl,AObject const* pr)
{

}
