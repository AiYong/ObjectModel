#ifndef ADOUBLE_H
#define ADOUBLE_H

#include "ANumber.h"

class ADouble : public ANumber
{
    A_OBJECT(ADouble)
public:

    ADouble();

    ADouble(double dValue);

    ADouble(ADouble const& rOther);

    ADouble& operator=(ADouble const& rOther);

    virtual ~ADouble();

public:


public:

    virtual ALong* LongValue() const ;

    virtual AInteger* IntegerValue() const ;

    virtual AShort* ShortValue() const ;

    virtual AUnsignedLong* UnsignedLongValue() const ;

    virtual AUnsignedInteger* IUnsignedntegerValue() const ;

    virtual AUnsignedShort* UnsignedShortValue() const ;

    virtual AFloat* Float() const ;

    virtual ADouble* Double() const ;

public:


};

#endif // ADOUBLE_H
