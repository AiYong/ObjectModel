#ifndef APARAMETER_H
#define APARAMETER_H

#include "AString.h"

class AClass;

class AParameter
{
public:

    AParameter();

    virtual ~AParameter();

public:

    /**
     * @brief GetName
     * @return
     */
    virtual AString const& GetName() = 0;

    /**
     * @brief GetType
     * @return
     */
    virtual AClass* GetType() = 0;



};

#endif // APARAMETER_H
