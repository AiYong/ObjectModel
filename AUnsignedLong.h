#ifndef AUNSIGNEDLONG_H
#define AUNSIGNEDLONG_H

#include "ANumber.h"

class AUnsignedLong : public ANumber
{
public:
    AUnsignedLong();

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

#endif // AUNSIGNEDLONG_H
