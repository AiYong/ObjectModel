#ifndef ALONG_H
#define ALONG_H

#include "ANumber.h"

class ALong : public ANumber
{
    A_OBJECT()
public:
        
    ALong();

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

#endif // ALONG_H
