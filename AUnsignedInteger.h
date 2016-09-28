#ifndef AUNSIGNEDINTEGER_H
#define AUNSIGNEDINTEGER_H

#include "ANumber.h"

class AUnsignedInteger : public ANumber
{
    A_OBJECT(AUnsignedInteger)
public:
    AUnsignedInteger();

public:

    virtual ALong* LongValue() const ;

    virtual AInteger* IntegerValue() const ;

    virtual AShort* ShortValue() const ;

    virtual AUnsignedLong* UnsignedLongValue() const ;

    virtual AUnsignedInteger* IUnsignedntegerValue() const ;

    virtual AUnsignedShort* UnsignedShortValue() const ;

    virtual AFloat* Float() const ;

    virtual ADouble* Double() const ;

};

#endif // AUNSIGNEDINTEGER_H
