#ifndef AOBJECT_H
#define AOBJECT_H

#include "AObjDefs.h"

class AClass;

class AObject
{
    A_OBJECT(AObject)
public:

    AObject();

    virtual ~AObject();

public:

    AClass* GetClass();
};

#endif // AOBJECT_H
