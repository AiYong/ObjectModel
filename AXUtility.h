#ifndef AXUTILITY_H
#define AXUTILITY_H

#include <type_traits>

using namespace std;

struct _ContainerProxy;
struct _ContainerBase12;
struct _IteratorBase12;


struct _ContainerBase0
{
    void _OrphanAll()
    {
    }

    void _SwapAll()
    {
    }
};

struct _IteratorBase0
{
    void _Adopt(const void*)
    {
    }

    const _ContainerBase0* _GetCont() const
    {
    }
};

struct _ContainerProxy
{
    _ContainerProxy()
        :_pMyCont(nullptr),_pMyFirstIter(nullptr)
    {
    }

   _ContainerBase12 const* _pMyCont;
   _IteratorBase12 *_pMyFirstIter;
};


struct _ContainerBase12
{
public:
    _ContainerBase12()
        :_pMyProxy(nullptr)
    {
    }

    _ContainerBase12(_ContainerBase12 const&)
        :_pMyProxy(nullptr)
    {
    }

    _ContainerBase12& operator=(_ContainerBase12 const&)
    {
        return (*this);
    }

    ~_ContainerBase12(_ContainerBase12&) noexcept
    {
        _OrphanAll();
    }

    _IteratorBase12** _GetPFirst() const
    {
        return (_pMyProxy == nullptr ? nullptr :&(_pMyProxy->_pMyFirstIter));
    }

    void _OrphanAll();
    void _SwapAll(_ContainerBase12& _Right);

    _ContainerProxy *_pMyProxy;
};

struct _IteratorBase12
{
public:
    _IteratorBase12()
        :_pMyProxy(nullptr),_pMyNextIter(nullptr)
    {
    }

    _IteratorBase12(_IteratorBase12 const&)
        :_pMyProxy(nullptr),_pMyNextIter(nullptr)
    {
    }

    _IteratorBase12& operator=(_IteratorBase12 const& _Right)
    {
        if(_pMyProxy == _Right._pMyProxy)
            ;
        else if(_Right._pMyProxy != nullptr)
        {
            _Adopt(_Right._pMyProxy->_pMyCont);
        }
    }

    ~_IteratorBase12() noexcept
    {
    }

    void _Adopt(_ContainerBase12 *_pParent)
    {
        if(_pParent != nullptr)
        {
            _pMyProxy = _pParent->_pMyProxy;
        }
    }

    void _ClrCont()
    {
        _pMyProxy = nullptr;
    }

    _ContainerBase12** _GetPNext()
    {
        return (&_pMyNextIter);
    }

    _ContainerProxy *_pMyProxy;
    _IteratorBase12 *_pMyNextIter;
};


inline void _ContainerBase12::_OrphanAll()
{

}

inline void _ContainerBase12::_SwapAll(_ContainerBase12& _Right)
{

}

typedef _ContainerBase0 _ContainerBase;
typedef _IteratorBase0 _IteratorBase;

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

    _Ty2& GetSecond() noexcept
    {
        return (_oMyVal2);
    }

    _Ty2 const& GetSecond() const noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2& GetSecond() volatile noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2 const& GetSecond() const volatile noexcept
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

    _Ty2& GetSecond() noexcept
    {
        return (_oMyVal2);
    }

    _Ty2 const& GetSecond() const noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2& GetSecond() volatile noexcept
    {
        return (_oMyVal2);
    }

    volatile _Ty2 const& GetSecond() const volatile noexcept
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


#endif // AXUTILITY_H
