#ifndef APARAMETER_H
#define APARAMETER_H

#include "AString.h"

class AClass;

/**
 * @brief The AParameter class
 */
class AParameter
{
public:

    /**
     * @brief AParameter
     */
    AParameter();

    /**
     * @brief ~AParameter
     */
    virtual ~AParameter();

public:

    /**
     * @brief GetName
     * @return
     */
    virtual AString const& GetName() const = 0;

    /**
     * @brief GetType
     * @return
     */
    virtual AClass* GetType() const = 0;


};

#endif // APARAMETER_H
