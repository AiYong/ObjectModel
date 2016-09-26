#include "AClass.h"
#include "AClassLoader.h"

AClass* AClass::LoadForName(AString const& strName )
{
    return GetClassLoader()->LoadForName(strName);
}

AList<AClass*> AClass::LoadAll()
{
    return GetClassLoader()->LoadAll();
}

AList<AClass*> AClass::LoadFrom(AString const& strPath)
{
    return GetClassLoader()->LoadFrom(strPath);
}

AClassLoader* AClass::GetClassLoader()
{
    static AClassLoader oInstance;
    return &oInstance;
}
