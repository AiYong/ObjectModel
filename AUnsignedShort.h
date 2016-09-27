#ifndef AUNSIGNEDSHORT_H
#define AUNSIGNEDSHORT_H

#include "ANumber.h"

class AUnsignedShort : public ANumber
{
    A_OBJECT(AUnsignedShort)
public:

    AUnsignedShort();

public:

    virtual ALong LongValue() const ;

    virtual AInteger IntegerValue() const ;

    virtual AShort ShortValue() const ;

    virtual AUnsignedLong UnsignedLongValue() const ;

    virtual AUnsignedInteger IUnsignedntegerValue() const ;

    virtual AUnsignedShort UnsignedShortValue() const ;

    virtual AFloat Float() const ;

    virtual ADouble Double() const ;
};

#endif // AUNSIGNEDSHORT_H
