#ifndef ASHORT_H
#define ASHORT_H

#include "ANumber.h"

class AShort : public ANumber
{
    A_OBJECT(AShort)
public:
    AShort();

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

#endif // ASHORT_H
