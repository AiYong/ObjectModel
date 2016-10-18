#ifndef AXUTILITY_H
#define AXUTILITY_H

#include <type_traits>

#include "ATypeTraits.h"

using namespace std;


struct _ZeroThenVariadicArgsT
{
};

struct _OneThenVariadicArgsT
{
};

template<typename _Ty1,
         typename _Ty2,
         bool = is_empty<_Ty1>::value && !is_final<_Ty1>::value>
class _CompressedPair final : private _Ty1
{
public:
    template<typename... _Other2>
    constexpr explicit _CompressedPair(_ZeroThenVariadicArgsT,_Other2&&... _rVal2)
        :_Ty1(),_oMyVal2(forward<_Other2>(_rVal2)...)
    {
    }

    template<typename _Other1,typename... _Other2>
    constexpr explicit _CompressedPair(_OneThenVariadicArgsT,_Other1&& _rVal1,_Other2&&... _rVal2)
        :_Ty1(forward<_Other1>(rVal1)),_oMyVal2(forward<_Other2>(_rVal2)...)
    {
    }

    _Ty1& _GetFirst() noexcept
    {
        return (*this);
    }

    _Ty1 const& _GetFirst() const noexcept
    {
        return (*this);
    }

    volatile _Ty1& _GetFirst() volatile noexcept
    {
        return (*this);
    }

    volatile _Ty1 const& _GetFirst() volatile const noexcept
    {
        return (*this);
    }

    _Ty2& _GetSecond() noexcept
    {
        return (_oMyVal2);
    }

    _Ty2 const& _GetSecond() const noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2& _GetSecond() volatile noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2 const& _GetSecond() const volatile noexcept
    {
        return (_oMyVal2);
    }

private:
    _Ty2 _oMyVal2;

};

template<typename _Ty1, typename _Ty2>
class _CompressedPair<_Ty1,_Ty2,false> final
{
public:
    template<typename... _Other2>
    constexpr explicit _CompressedPair(_ZeroThenVariadicArgsT,_Other2&&... _rVal2)
        :_oMyVal1(),_oMyVal2(forward<_Other2>(_rVal2)...)
    {
    }

    template<typename _Other1,typename... _Other2>
    constexpr explicit _CompressedPair(_OneThenVariadicArgsT,_Other1&& _rVal1,_Other2&&... _rVal2)
        :_oMyVal1(forward<_Other1>(rVal1)),_oMyVal2(forward<_Other2>(_rVal2)...)
    {
    }

    _Ty1& _GetFirst() noexcept
    {
        return (_oMyVal1);
    }

    _Ty1 const& _GetFirst() const noexcept
    {
        return (_oMyVal1);
    }

    volatile _Ty1& _GetFirst() volatile noexcept
    {
        return (_oMyVal1);
    }

    volatile _Ty1 const& _GetFirst() volatile const noexcept
    {
        return (_oMyVal1);
    }

    _Ty2& _GetSecond() noexcept
    {
        return (_oMyVal2);
    }

    _Ty2 const& _GetSecond() const noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2& _GetSecond() volatile noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2 const& _GetSecond() const volatile noexcept
    {
        return (_oMyVal2);
    }

private:
    _Ty1 _oMyVal1;
    _Ty2 _oMyVal2;
};


struct InputIteratorTag
{
};

struct _MutableIteratorTag
{
};

struct OutputIteratorTag : _MutableIteratorTag
{
};

struct ForwardIteratorTag : InputIteratorTag,_MutableIteratorTag
{
};

struct BidirectionalIteratorTag : ForwardIteratorTag
{
};

struct RandomAccessIteratorTag : BidirectionalIteratorTag
{
};


template<typename _Category,
         typename _Ty,
         typename _Diff = ptrdiff_t,
         typename _Pointer = _Ty*,
         typename _Reference = _Ty&>
struct Iterator
{
    typedef _Category IteratorCategofy;
    typedef _Ty ValueType;
    typedef _Diff DifferenceType;
    typedef _Pointer Pointer;
    typedef _Reference Reference;
};

template<typename _Category,
         typename _Ty,
         typename _Diff,
         typename _Pointer,
         typename _Reference,
         typename _Base>
struct Iterator012 : public _Base
{
    typedef _Category IteratorCategofy;
    typedef _Ty ValueType;
    typedef _Diff DifferenceType;
    typedef _Pointer Pointer;
    typedef _Reference Reference;
};

template<typename,typename = void>
struct _IteratorTraitsBase
{
};

template<typename _Iter>
struct _IteratorTraitsBase<_Iter,VoidT<
        typename _Iter::IteratorCategory,
        typename _Iter::ValueType,
        typename _Iter::DifferenceType,
        typename _Iter::Pointer,
        typename _Iter::Reference>>
{
    typedef typename _Iter::IteratorCategory IteratorCategofy;
    typedef typename _Iter::ValueType ValueType;
    typedef typename _Iter::DifferenceType DifferenceType;
    typedef typename _Iter::Pointer Pointer;
    typedef typename _Iter::Reference Reference;
};

template<typename _Iter>
struct IteratorTraits : _IteratorTraitsBase<_Iter>
{
};

template<typename _Ty>
struct IteratorTraits<_Ty*>
{
    typedef RandomAccessIteratorTag IteratorCategofy;
    typedef _Ty ValueType;
    typedef ptrdiff_t DifferenceType;
    typedef _Ty* Pointer;
    typedef _Ty& Reference;
};

template<typename _Ty>
struct IteratorTraits< const _Ty*>
{
    typedef RandomAccessIteratorTag IteratorCategofy;
    typedef _Ty ValueType;
    typedef ptrdiff_t DifferenceType;
    typedef _Ty* Pointer;
    typedef _Ty& Reference;
};

template<typename _Iter,typename = void>
struct _IsIterator : std::false_type
{
};


template<typename _Iter>
struct _IsIterator<_Iter,VoidT<
        typename _Iter::IteratorCategory,
        typename _Iter::ValueType,
        typename _Iter::DifferenceType,
        typename _Iter::Pointer,
        typename _Iter::Reference>> : std::true_type
{
};

#endif // AXUTILITY_H
