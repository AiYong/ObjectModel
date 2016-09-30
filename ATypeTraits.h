#ifndef ATYPETRAITS_H
#define ATYPETRAITS_H

#include <type_traits>


template<typename...>
struct _ParamTester
{
    typedef void Type;
};

template<typename... _Types>
using VoidT = typename _ParamTester<_Types...>::Type;


template<typename _Ty>
struct RemoveReference
{

};

#endif // ATYPETRAITS_H
