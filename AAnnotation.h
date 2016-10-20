#ifndef AANNOTATION_H
#define AANNOTATION_H

#include "AObject.h"
#include "AString.h"

class AAnnotation : public AObject
{
    A_ANNOTATION()
public:

    AAnnotation();

    virtual ~AAnnotation();

public:

    virtual AString const& GetName() const;
};

#endif // AANNOTATION_H
