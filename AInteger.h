#ifndef AINTEGER_H
#define AINTEGER_H

#include "ANumber.h"

class AInteger : public ANumber
{
public:
    AInteger();

public:

    virtual ALong* LongValue() const ;

    virtual AInteger* IntegerValue() const ;

    virtual AShort* ShortValue() const ;

    virtual AUnsignedLong* UnsignedLongValue() const ;

    virtual AUnsignedInteger* IUnsignedntegerValue() const ;

    virtual AUnsignedShort* UnsignedShortValue() const ;

    virtual AFloat* Float() const ;

    virtual ADouble Double() const ;

};

#endif // AINTEGER_H
