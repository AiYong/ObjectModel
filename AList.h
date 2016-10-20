#ifndef ALIST_H
#define ALIST_H

#include "AObject.h"
#include <list>
#include <iterator>
#include <type_traits>

#include "AMemory.h"
#include "AXUtility.h"

struct _ListNodeBase
{
   _ListNodeBase *_pNext;
   _ListNodeBase *_pPrev;
};

template<typename _Ty>
struct _ListNode : _ListNodeBase
{
    _Ty _oData;
    template<typename... _Args>
    _ListNode(_Args&&... _rArgs)
        :_ListNodeBase(),_oData(std::forward<_Args>(_rArgs)...)
    {
    }
};

template<typename _Ty>
struct _ListIterator : AObject
{
    A_OBJECT()

    typedef _ListIterator<_Ty>          _MyType;
    typedef _ListNode<_Ty>              _NodeType;

    typedef ptrdiff_t                   Difference;
    typedef BidirectionalIteratorTag    IteratorCategory;
    typedef _Ty                         ValueType;
    typedef _Ty*                        Pointer;
    typedef _Ty&                        Reference;

    _ListIterator()
        :_pNode()
    {
    }

    explicit _ListIterator(_ListNodeBase *_pValue)
        :_pNode(_pValue)
    {
    }

    Reference operator*() const
    {
        return (static_cast<_NodeType*>(_pNode)->_oData);
    }

    Pointer operator*() const
    {
        return (&(static_cast<_NodeType*>(_pNode)->_oData));
    }

    _MyType& operator++()
    {
        _pNode = _pNode->_pNext;
        return (*this);
    }

    _MyType operator++(int)
    {
        _MyType _Tmp = *this;
        _pNode = _pNode->_pNext;
        return (_Tmp);
    }

    _MyType& operator--()
    {
        _pNode = _pNode->_pPrev;
        return (*this);
    }

    _MyType operator--(int)
    {
        _MyType _Tmp = *this;
        _pNode = _pNode->_pPrev;
        return (_Tmp);
    }

    _MyType& operator=(_MyType const& _Right)
    {
        _pNode = _Right._pNode;
        return (*this);
    }

    bool operator==(_MyType const& _Right)
    {
        return (_pNode == _Right._pNode);
    }

    bool operator!=(_MyType const& _Right)
    {
        return (_pNode == _Right._pNode);
    }

    _ListNodeBase *_pNode;
};


template<typename _Ty>
struct _ListConstIterator : AObject
{
    A_OBJECT()

    typedef _ListConstIterator<_Ty>     _MyType;
    typedef _ListNode<_Ty>              _NodeType;
    typedef _ListIterator<_Ty>          Iterator;
    typedef ptrdiff_t                   Difference;
    typedef BidirectionalIteratorTag    IteratorCategory;
    typedef _Ty                         ValueType;
    typedef _Ty*                        Pointer;
    typedef _Ty&                        Reference;

    _ListConstIterator()
        :_pNode()
    {
    }

    explicit _ListConstIterator(_ListNodeBase *_pValue)
        :_pNode(_pValue)
    {
    }

    explicit _ListConstIterator(Iterator const& rIter)
        :_pNode(rIter._pNode)
    {
    }

    Reference operator*() const
    {
        return (static_cast<_NodeType*>(_pNode)->_oData);
    }

    Pointer operator*() const
    {
        return (&(static_cast<_NodeType*>(_pNode)->_oData));
    }

    _MyType& operator++()
    {
        _pNode = _pNode->_pNext;
        return (*this);
    }

    _MyType operator++(int)
    {
        _MyType _Tmp = *this;
        _pNode = _pNode->_pNext;
        return (_Tmp);
    }

    _MyType& operator--()
    {
        _pNode = _pNode->_pPrev;
        return (*this);
    }

    _MyType operator--(int)
    {
        _MyType _Tmp = *this;
        _pNode = _pNode->_pPrev;
        return (_Tmp);
    }

    _MyType& operator=(_MyType const& _Right)
    {
        _pNode = _Right._pNode;
        return (*this);
    }

    bool operator==(_MyType const& _Right)
    {
        return (_pNode == _Right._pNode);
    }

    bool operator!=(_MyType const& _Right)
    {
        return (_pNode == _Right._pNode);
    }

    _ListNodeBase *_pNode;
};

template<typename _Ty>
inline bool operator==(_ListIterator<_Ty>& _rLeft,_ListConstIterator<_Ty> const& _rRight)
{
    return (_rLeft._pNode == _rRight._pNode);
}

template<typename _Ty>
inline bool operator!=(_ListIterator<_Ty>& _rLeft,_ListConstIterator<_Ty> const& _rRight)
{
    return (_rLeft._pNode != _rRight._pNode);
}



template<typename _ValueTypes>
class _ListVal
{
public:
    typedef typename _ValueTypes::ValueType                 ValueType;
    typedef typename _ValueTypes::Pointer                   Pointer;
    typedef typename _ValueTypes::ConstPointer              ConstPointer;
    typedef typename _ValueTypes::Reference                 Reference;
    typedef typename _ValueTypes::ConstReference            ConstReference;

    typedef typename _ValueTypes::Iterator                  Iterator;
    typedef typename _ValueTypes::ConstIterator             ConstIterator;
    typedef typename _ValueTypes::ReverseIterator           ReverseIterator;
    typedef typename _ValueTypes::ConstReverseIterator      ConstReverseIterator;
    typedef typename _ValueTypes::SizeType                  SizeType;
    typedef typename _ValueTypes::AllocatorType             AllocatorType;

    typedef typename _ValueTypes::_NodeType                 _NodeType;
    typedef typename _ValueTypes::_NodePtr                  _NodePtr;
    typedef typename _ValueTypes::_NodePtrRef               _NodePtrRef;
    typedef typename _ValueTypes::_HeadNodeType             _HeadNodeType;

    _ListVal()
        :_oMyHead()
    {
    }

    _HeadNodeType _oMyHead;
};

template<typename _ListAlloc>
struct _ListValTypes
{
    typedef typename _ListAlloc::ValueType                 ValueType;
    typedef typename _ListAlloc::Pointer                   Pointer;
    typedef typename _ListAlloc::ConstPointer              ConstPointer;
    typedef typename _ListAlloc::Reference                 Reference;
    typedef typename _ListAlloc::ConstReference            ConstReference;

    typedef typename _ListAlloc::Iterator                  Iterator;
    typedef typename _ListAlloc::ConstIterator             ConstIterator;
    typedef typename _ListAlloc::ReverseIterator           ReverseIterator;
    typedef typename _ListAlloc::ConstReverseIterator      ConstReverseIterator;
    typedef typename _ListAlloc::SizeType                  SizeType;
    typedef typename _ListAlloc::AllocatorType             AllocatorType;

    typedef typename _ListAlloc::_NodeType                 _NodeType;
    typedef typename _ListAlloc::_NodePtr                  _NodePtr;
    typedef typename _ListAlloc::_NodePtrRef               _NodePtrRef;
    typedef typename _ListAlloc::_HeadNodeType             _HeadNodeType;
};

template<typename _Ty,typename _Alloc>
class _ListAlloc : public AObject
{
    A_OBJECT()
public:
    typedef _Ty                                     ValueType;
    typedef typename _Alloc::pointer                Pointer;
    typedef typename _Alloc::const_pointer          ConstPointer;
    typedef typename _Alloc::reference              Reference;
    typedef typename _Alloc::const_reference        ConstReference;
    typedef _ListIterator<_Ty>                      Iterator;
    typedef _ListConstIterator<_Ty>                 ConstIterator;
    typedef std::reverse_iterator<Iterator>         ReverseIterator;
    typedef std::reverse_iterator<ConstIterator>    ConstReverseIterator;
    typedef size_t                                  SizeType;
    typedef _Alloc                                  AllocatorType;

    typedef _ListNode<_Ty>                          _NodeType;
    typedef _ListNode<_Ty>*                         _NodePtr;
    typedef _ListNode<SizeType>                     _HeadNodeType;
    typedef _NodePtr&                               _NodePtrRef;
    typedef _ListAlloc<_Ty,_Alloc>                  _MyType;
    typedef _ListVal<_ListValTypes<_MyType>>        _ListValType;
    typedef typename _Alloc::template rebind<_ListNode<_Ty>>::other
    _NodeAllocatorType;

    _ListAlloc()
        :_oPair(_ZeroThenVariadicArgsT())
    {
    }

    _ListAlloc(AllocatorType const&)
        :_oPair(_ZeroThenVariadicArgsT(),_NodeAllocatorType())
    {
    }

    AllocatorType& _GetAlloc()
    {
        return _oPair._GetFirst();
    }

    _ListValType& _GetVal()
    {
        return _oPair._GetSecond();
    }

    _NodePtr _GetHead()
    {
        return (&(_GetVal()._oMyHead));
    }

    SizeType& _GetSize()
    {
        return (_GetVal()._oMyHead._oData);
    }

    void _SetSize(SizeType nSize)
    {
        _GetSize() = nSize;
    }

    _NodePtr _NewNode()
    {
        AllocatorType& rAlloc = _GetAlloc();
        return rAlloc.allocate(1);
    }

    template<typename... _Args>
    _NodePtr _NewNodeAndConstruct(Args&&... _rArgs)
    {
        _NodePtr _pNode = _NewNode();
        try
        {
            AllocatorType& rAlloc = _GetAlloc();
            rAlloc.construct(_p,std::forward<_Args>(_rArgs)...);
        }catch(...)
        {
            _DeleteNode(_pNode);
            std::rethrow_exception(std::current_exception());
        }
        return _pNode;
    }

    _NodePtr _DeleteNode(_NodePtr _pNode)
    {
        AllocatorType& rAlloc = _GetAlloc();
        rAlloc.deallocate(_pNode);
    }

    _CompressedPair<_NodeAllocatorType,_ListValType> _oPair;
};


template<typename _Ty,typename _Alloc>
class _ListBase : public _ListAlloc<_Ty,_Alloc>
{
    A_OBJECT()
public:

    typedef _ListAlloc<_Ty,_Alloc>                      _MyBase;

    typedef typename _MyBase::ValueType                 ValueType;
    typedef typename _MyBase::Pointer                   Pointer;
    typedef typename _MyBase::ConstPointer              ConstPointer;
    typedef typename _MyBase::Reference                 Reference;
    typedef typename _MyBase::ConstReference            ConstReference;

    typedef typename _MyBase::Iterator                  Iterator;
    typedef typename _MyBase::ConstIterator             ConstIterator;
    typedef typename _MyBase::ReverseIterator           ReverseIterator;
    typedef typename _MyBase::ConstReverseIterator      ConstReverseIterator;
    typedef typename _MyBase::SizeType                  SizeType;
    typedef typename _MyBase::AllocatorType             AllocatorType;

    typedef typename _MyBase::_NodeType                 _NodeType;
    typedef typename _MyBase::_NodeAllocatorType        _NodeAllocatorType;


    _ListBase()
        :_MyBase()
    {
        _Init();
    }

    _ListBase(AllocatorType const& _rAlloc)
        :_MyBase(_rAlloc)
    {
        _Init();
    }
    
    _ListBase(_ListBase&& rOther)
        :_MyBase()
    {
        _Steal(std::move(rOther));
    }

    _ListBase(_ListBase&& rOther,AllocatorType const& _rAlloc)
        :_MyBase(_rAlloc)
    {
        _Steal(std::move(rOther));
    }

    void _Init()
    {
        _NodePtr _pMyHead = _GetHead();
        _pMyHead->_pNext = _pMyHead;
        _pMyHead->_pPrev = _pMyHead;
        _SetSize(0);
    }

    void _Steal(_ListBase&& rOther)
    {

    }

    void _Clear()
    {
        _NodePtr _pHead = _GetHead();
        _NodePtr _pNode = _pHead->_pNext;
        while(_pNode != _pHead)
        {
            _NodePtr _pTmp = _pNode;
            _pNode = _pNode->_pNext;
            _DeleteNode(_pTep);
        }
    }

    void _DefaultInitialize(SizeType nCount)
    {
        for(;nCount > 0 ; nCount--)
        {
            _EmplaceBack();
        }
    }

    void _FillInitialize(SizeType nCount,ValueType const& rValue)
    {
        for(;nCount > 0 ; nCount--)
        {
            _PushBack(rValue);
        }
    }

    void _FillAssign(SizeType nCount ,ValueType const& rValue)
    {

    }

    template<typename _InputIt>
    void _IteratorInitialize(_InputIt iFirst,_InputIt iLast)
    {
        for(;iFirst != iLast ; iFirst++)
        {
            _EmplaceBack(*iFirst);
        }
    }
    
    template<typename _InputIt>
    void _IteratorAssign(_InputIt iFirst,_InputIt iLast)
    {

    }

    void _InitializerListAssign(std::initializer_list<ValueType> oInit)
    {
        _IteratorInitialize(oInit.begin(),oInit.end());
    }

    void _DefaultAppend(SizeType nCount)
    {
        for(;nCount > 0 ; nCount--)
        {
            _EmplaceBack();
        }
    }

    void _ValueAppend(ValueType const& rValue)
    {
        for(;nCount > 0 ; nCount--)
        {
            _EmplaceBack(rValue);
        }
    }

    template<typename _InputIt>
    void _PositionInsert(_InputIt iPos,ValueType const& rValue)
    {

    }

    template<typename _InputIt>
    void _PositionInsert(_InputIt iPos,ValueType && rValue)
    {

    }

    template<typename _InputIt>
    void _PositionFill(_InputIt iPos,SizeType nCount,ValueType const& rValue)
    {

    }

    template<typename _InputIt>
    void _PositionIteratorInsert(Iterator iPos, _InputIt iFirst,_InputIt iLast)
    {

    }

    template<typename _InputIt>
    void _PositionIteratorInsert(ConstIterator iPos, _InputIt iFirst,_InputIt iLast)
    {

    }

    template<typename _InputIt>
    void _IteratorInsert(_InputIt iFirst,_InputIt iLast)
    {

    }
    
    template<typename... _Args>
    void _Insert(Iterator iPos,_Args&&... _rArgs)
    {
        _NodePtr _pTmp = _NewNode();
        
    }
    
    template<typename... _Args>
    void _EmplaceBack(_Args... _rArgs)
    {
        
    }
    
    void _PushBack(ValueType const& rValue)
    {
        
    }
    
    void _PushFront(ValueType const& rValue)
    {
        
    }

};


template<typename _Ty,typename _Alloc = std::allocator<_Ty>>
class AList : protected _ListBase<_Ty,_Alloc>
{
    A_OBJECT()
public:

    typedef _ListBase<_Ty,_Alloc> _MyBase;
    typedef AList<_Ty,_Alloc> _MyType;

public:

    AList():_MyBase()
    {
    }

    explicit AList(AllocatorType const& rAlloc)
        :_MyBase(rAlloc)
    {
    }

    AList(SizeType nCount,ValueType const& rValue,AllocatorType const& rAlloc = AllocatorType())
        :_MyBase(rAlloc)
    {
        _FillInitialize(nCount,rValue);
    }

    explicit AList(SizeType nCount)
        :_MyBase()
    {
        _DefaultInitialize(nCount);
    }

    explicit AList(SizeType nCount,AllocatorType const& rAlloc)
        :_MyBase(rAlloc)
    {
        _DefaultInitialize(nCount);
    }

    template<typename InputIt>
    AList(InputIt iFirst,InputIt iLast,AllocatorType const& rAlloc)
        :_MyBase(rAlloc)
    {
        _IteratorInitialize(iFirst,iLast);
    }

    AList(_MyType const& rOther)
        :_MyBase()
    {
        _IteratorInitialize(rOther.Begin(),rOther.End());
    }

    AList(_MyType const& rOther,AllocatorType const& rAlloc)
        :_MyBase(rAlloc)
    {
        _IteratorInitialize(rOther.Begin(),rOther.End());
    }

    AList(_MyType && rOther)
        :_MyBase(std::move(rOther))
    {
    }

    AList(_MyType && rOther,AllocatorType const& rAlloc)
    :_MyBase(std::move(rOther),rAlloc)
    {
    }

    AList(std::initializer_list<_Ty> oInit,AllocatorType const& rAlloc)
        :_MyBase(rAlloc)
    {
        _IteratorInitialize(oInit.begin(),oInit.end());
    }

    AList& operator=(_MyType const& rOther)
    {

        return (*this);
    }

    AList& operator=(_MyType && rOther)
    {
        _Clear();
        _Steal(std::move(rOther));
        return (*this);
    }

    AList& operator=(std::initializer_list<_Ty> oInit)
    {
       _IteratorAssign(oInit.begin(),oInit.end());
       return (*this);
    }

    ~AList()
    {
        _Clear();
    }

public:

    void Clear()
    {
        _Clear();
        _Init();
    }

public:

    void Assign(SizeType nCount,ValueType const& rValue)
    {
        _FillAssign(nCount,rValue);
    }

    template<class InputIt>
    std::enable_if<_IsIterator<InputIt>::value,void>::type
     Assign(InputIt iFirst,InputIt iLast)
    {
        _IteratorAssign(iFirst,iLast);
    }

    void Assign(std::initializer_list<_Ty> oInit)
    {
        _IteratorAssign(oInit.begin(),oInit.end());
    }

public:

    AllocatorType GetAllocator() const
    {

    }

public:

    Reference Front()
    {
        return (*Begin());
    }

    ConstReference Front() const
    {
        return (*Begin());
    }


    Reference Back()
    {
        return (*End());
    }

    ConstReference Back() const
    {
        return (*End());
    }

public:

    Iterator Begin()
    {
        return Iterator(_GetHead()->_pNext);
    }

    ConstIterator Begin() const
    {
        return ConstIterator(_GetHead()->_pNext);
    }

    ConstIterator CBegin() const
    {
        return ConstIterator(_GetHead()->_pNext);
    }

    Iterator End()
    {
        return Iterator(_GetHead());
    }

    ConstIterator End() const
    {
        return ConstIterator(_GetHead());
    }

    ConstIterator CEnd() const
    {
        return ConstIterator(_GetHead());
    }

public:

    ReverseIterator RBegin()
    {
        return ReverseIterator(Begin());
    }

    ConstReverseIterator RBegin() const
    {
        return ConstReverseIterator(Begin());
    }

    ConstReverseIterator CRBegin() const
    {
        return ConstReverseIterator(Begin());
    }

    ReverseIterator REnd()
    {
        return ReverseIterator(End());
    }

    ConstReverseIterator REnd() const
    {
        return ConstReverseIterator(End());
    }

    ConstReverseIterator CREnd() const
    {
        return ConstReverseIterator(End());
    }

public:

    bool Empty() const
    {
        return _GetSize() == 0;
    }

    SizeType Size() const
    {
        return _GetSize();
    }

    SizeType MaxSize() const
    {
        return _GetAlloc().max_size();
    }

public:

    void Clear()
    {
        _Clear();
    }

    Iterator Insert(Iterator iPos, ValueType const& rValue)
    {
        _PositionInsert(iPos,rValue);
    }

    Iterator Insert(ConstIterator iPos, ValueType const& rValue)
    {
        _PositionInsert(iPos,rValue);
    }

    Iterator Insert(ConstIterator iPos, ValueType &&rValue)
    {
        _PositionInsert(iPos,std::forward<ValueType>(rValue));
    }

    void Insert(Iterator iPos, SizeType nCount,const ValueType &rValue)
    {
        _PositionFill(iPos,nCount,rValue);
    }

    Iterator Insert(ConstIterator iPos, SizeType nCount,const ValueType &rValue)
    {
        _PositionFill(iPos,nCount,rValue);
    }

    template<class InputIt>
    void Insert(Iterator iPos,InputIt iFirst,InputIt iLast)
    {
        _PositionIteratorInsert(iPos,iFirst,iLast);
    }

    template<class InputIt>
    void Insert(ConstIterator iPos,InputIt iFirst,InputIt iLast)
    {
        _PositionIteratorInsert(iPos,iFirst,iLast);
    }

    Iterator Insert(ConstIterator iPos, std::initializer_list<ValueType> oInit)
    {
        PositionIteratorInsert(iPos,oInit.begin(),oInit.end());
    }

    template<typename ...Args>
    Iterator Emplace(ConstIterator iPos,Args&& ...args)
    {

    }

public:

    Iterator Erase(Iterator iPos)
    {

    }

    Iterator Erase(ConstIterator iPos)
    {

    }

    Iterator Erase(Iterator iFirst,Iterator iLast)
    {

    }

    Iterator Erase(ConstIterator iFirst,ConstIterator iLast)
    {

    }

public:

    void PushBack(ValueType const& rValue)
    {

    }

    void PushBack(ValueType &&rValue)
    {

    }

public:

    template<typename... Args>
    void EmplaceBack(Args&&... args)
    {

    }

public:

    void PopBack()
    {

    }

public:

    void PushFront(ValueType const& rValue)
    {

    }

    void PushFront(ValueType && rValue)
    {

    }

public:

    template<typename... Args>
    void EmplaceFront(Args&&... args)
    {

    }

public:

    void PopFront()
    {

    }

public:

    void Resize(SizeType nCount, ValueType oValue = ValueType())
    {

    }

    void Resize(SizeType nCount)
    {

    }

    void Resize(SizeType nCount, ValueType const& rValue)
    {

    }

public:

    void Swap(_MyType &rOther)
    {

    }

public:

    void Merge(_MyType &rOther)
    {

    }

    void Merge(_MyType &&rOther)
    {

    }

    template<typename Compare>
    void Merge(_MyType &rOther,Compare comp)
    {

    }

    template<typename Compare>
    void Merge(_MyType &&rOther,Compare comp)
    {

    }

public:

    void Splice(ConstIterator iPos,_MyType &rOther)
    {

    }

    void Splice(ConstIterator iPos, _MyType &&rOther)
    {

    }

    void Splice(ConstIterator iPos,_MyType &rOther,ConstIterator iIt)
    {

    }

    void Splice(ConstIterator iPos, _MyType &&rOther,ConstIterator iIt)
    {

    }

    void Splice(ConstIterator iPos,_MyType &rOther,ConstIterator iFirst,ConstIterator iLast)
    {

    }

    void Splice(ConstIterator iPos, _MyType &&rOther,ConstIterator iFirst,ConstIterator iLast)
    {

    }

public:

    void Remove(ValueType const& rValue)
    {

    }

    template<typename Predicate>
    void RemoveIf(Predicate oPredicate)
    {

    }

public:

    void Reverse()
    {

    }

public:

    void Unique()
    {

    }

    template<typename Predicate>
    void Unique(Predicate oPred)
    {

    }

public:

    void Sort()
    {

    }

    template<typename Compare>
    void Sort(Compare oComp)
    {

    }
};

template< class Ty, class Alloc >
bool operator==(  AList<Ty,Alloc> const& lhs,  AList<Ty,Alloc> const& rhs )
{

}

template< class Ty, class Alloc >
bool operator!=( AList<Ty,Alloc> const& lhs,  AList<Ty,Alloc> const& rhs )
{

}

template< class Ty, class Alloc >
bool operator<( AList<Ty,Alloc> const& lhs,  AList<Ty,Alloc> const& rhs )
{

}

template< class T, class Alloc >
bool operator<=( AList<T,Alloc> const& lhs,  AList<T,Alloc> const& rhs )
{

}

template< class Ty, class Alloc >
bool operator>( AList<Ty,Alloc> const& lhs,  AList<Ty,Alloc> const& rhs )
{

}

template< class Ty, class Alloc >
bool operator>=( AList<Ty,Alloc> const& lhs,  AList<Ty,Alloc> const& rhs )
{

}


#endif // ALIST_H
