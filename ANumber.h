#ifndef ANUMBER_H
#define ANUMBER_H

#include <stdint.h>

#include "AObject.h"

class ALong;
class AInteger;
class AShort;
class AUnsignedLong;
class AUnsignedInteger;
class AUnsignedShort;
class AFloat;
class ADouble;

class ANumber : public AObject
{
    A_OBJECT()
public:

    ANumber();

    virtual ~ANumber();

public:

    /**
     * @brief LongValue
     * @return
     */
    virtual ALong* LongValue() const = 0;

    /**
     * @brief IntegerValue
     * @return
     */
    virtual AInteger* IntegerValue() const = 0;

    /**
     * @brief ShortValue
     * @return
     */
    virtual AShort* ShortValue() const = 0;

    /**
     * @brief LongValue
     * @return
     */
    virtual AUnsignedLong* UnsignedLongValue() const = 0;

    /**
     * @brief IntegerValue
     * @return
     */
    virtual AUnsignedInteger* IUnsignedntegerValue() const = 0;

    /**
     * @brief ShortValue
     * @return
     */
    virtual AUnsignedShort* UnsignedShortValue() const = 0;

    /**
     * @brief Float
     * @return
     */
    virtual AFloat* Float() const = 0;

    /**
     * @brief Double
     * @return
     */
    virtual ADouble* Double() const = 0;

};

#endif // ANUMBER_H
