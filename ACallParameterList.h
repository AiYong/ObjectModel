#ifndef ACALLPARAMETERLIST_H
#define ACALLPARAMETERLIST_H

#include <type_traits>
#include "AObject.h"

class ACallParameterList
{
public:

    typedef _Elem value_type;
    typedef const _Elem& reference;
    typedef const _Elem& const_reference;
    typedef size_t size_type;
    typedef const _Elem* iterator;
    typedef const _Elem* const_iterator;

    constexpr ACallParameterList() noexcept
    : _First(0), _Last(0)
    {
    }

    constexpr ACallParameterList(const _Elem *_First_arg,
    const _Elem *_Last_arg) noexcept
    : _First(_First_arg), _Last(_Last_arg)
    {
    }

    constexpr const _Elem *begin() const noexcept
    {
    return (_First);
    }

    constexpr const _Elem *end() const noexcept
    {
    return (_Last);
    }

    constexpr size_t size() const noexcept
    {
    return ((size_t)(_Last - _First));
    }

private:
    const _Elem *_First;
    const _Elem *_Last;
};


template<class _Elem> inline
constexpr const _Elem *begin(ACallParameterList<_Elem> _Ilist) noexcept
{
return (_Ilist.begin());
}


template<class _Elem> inline
constexpr const _Elem *end(ACallParameterList<_Elem> _Ilist) noexcept
{
return (_Ilist.end());
}

#endif // ACALLPARAMETERLIST_H
