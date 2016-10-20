#ifndef AOBJECTACCESSOR_H
#define AOBJECTACCESSOR_H

#include "../AObjDefs.h"
#include "../AObject.h"

template<>
class AObjectAccessor<AObject>
{
public:

    void CallHashCode(AObject* pObj,size_t& nHashCode)
    {
        nHashCode = pObj->HashCode();
    }
};


#endif // AOBJECTACCESSOR_H
