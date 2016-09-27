#ifndef AARRAY_H
#define AARRAY_H

#include <array>
#include <unordered_map>

#include "AObject.h"

template<class _Ty,	size_t _Size>
class AArray : public AObject
{
    A_OBJECT(AArray)
public:

private:

  std::array<_Ty,_Size> m_oContainer;

};

#endif // AARRAY_H
