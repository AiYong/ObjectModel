#include "AObject.h"

AObject::AObject()
{
}

AObject::~AObject()
{
}

size_t AObject::HashCode()
{
    return size_t(reinterpret_cast<char*>(this));
}
