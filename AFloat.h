#ifndef AFLOAT_H
#define AFLOAT_H

#include "ANumber.h"

class AFloat : public ANumber
{
    A_OBJECT(AFloat)
public:

    AFloat();

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

#endif // AFLOAT_H
