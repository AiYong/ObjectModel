#include "AObject.h"

#include "AClass.h"

AObject::AObject()
{
}

AObject::~AObject()
{
}

AClass* AObject::GetClass()
{
    AClass::LoadForName(AString::FromLocaleString("AObject"));
}
