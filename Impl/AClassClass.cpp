#include "AClassClass.h"

AString const& AClassClass::GetName()
{

}

AList<AClass*> const& AClassClass::GetParentTypes()
{

}

AClass* AClassClass::GetParentType(AString const& strParentName)
{

}

AField* AClassClass::GetField( AString const& strFieldName )
{

}

AList<AField*> AClassClass::GetFields()
{

}

AField* AClassClass::GetDeclaredField(AString const& strFiledName)
{

}

AList<AField*> const& AClassClass::GetDeclaredFields()
{

}

AMethod* AClassClass::GetMethod( AString const& strMethodName )
{

}

AMethod* AClassClass::GetMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters)
{

}

AList<AMethod*>& AClassClass::GetMethods()
{

}

AMethod* AClassClass::GetDeclaredMethod( AString const& strMethodName )
{

}

AMethod* AClassClass::GetDeclaredMethod(AString const& strMethodName,std::initializer_list<AParameter*> const& lParameters)
{

}

AList<AMethod*>& AClassClass::GetDeclaredMethods()
{

}

AList<AAnnotation const*> AClassClass::GetAnnotations()
{

}

bool AClassClass::IsAbstract() const
{

}

AObject* AClassClass::NewInstance()
{

}

AObject* AClassClass::NewInstance(std::initializer_list<AParameter*> const& lParameters)
{

}

AObject* AClassClass::CopyInstance(AObject const* pObject)
{

}

void AClassClass::DeleteInstance(AObject const* pObject)
{

}

bool AClassClass::IsEqual(AObject const* pl,AObject const* pr)
{

}
