#ifndef AMETHOD_H
#define AMETHOD_H

#include <initializer_list>

#include "AList.h"

class AObject;
class AParameter;

class AMethod
{
public:

    enum Access
    {
        Private,
        Protected,
        Public
    }

    AMethod();

public:

    AList<AParameter*> const& GetParameters() const;

public:

    AObject* Call(AObject const* pObj,std::initializer_list<AObject*> const& lParameters);

};

#endif // AMETHOD_H
