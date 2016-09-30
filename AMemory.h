#ifndef AMEMORY_H
#define AMEMORY_H

#include <memory>

template<typename _Ty>
_Ty* AddressOf(_Ty& pObj)
{
    return std::addressof(pObj);
}

#endif // AMEMORY_H
