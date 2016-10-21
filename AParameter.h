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
    ~AParameter();

public:

    /**
     * @brief GetName
     * @return
     */
    AString GetName() const;

    /**
     * @brief GetType
     * @return
     */
     AClass* GetType() const = 0;

    /**
     * @brief GetModifiers
     * @return
     */
    int GetModifiers() const;

};

#endif // APARAMETER_H
