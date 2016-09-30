#ifndef ALIST_H
#define ALIST_H

#include "AObject.h"
#include <list>
#include <iterator>
#include <type_traits>

#include "AMemory.h"
#include "AXUtility.h"

template<typename _MyList,
         typename _Base = _IteratorBase0>
class _ListUncheckedConstIterator
        : public _Iterator012<BidirectionalIteratorTag,
          typename _MyList::ValueType,
          typename _MyList::DifferenceType,
          typename _MyList::ConstPointer,
          typename _MyList::ConstReference,
          _Base>
{
public:

    typedef _ListUncheckedConstIterator<_MyList,_Base> _MyIter;
    typedef BidirectionalIteratorTag IteratorCategory;
    typedef typename _MyList::_NodePtr _NodePtr;
    typedef typename _MyList::ValueType ValueType;
    typedef typename _MyList::DifferenceType DifferenceType;
    typedef typename _MyList::ConstPointer Pointer;
    typedef typename _MyList::ConstReference Reference;

    _ListUncheckedConstIterator():_Ptr(nullptr)
    {
    }

    _ListUncheckedConstIterator(_NodePtr _pNode,_MyList const* _pList)
        :_Ptr(_pNode)
    {
        this->_Adopt(_pList);
    }

    Reference operator*() const
    {
        return (_MyList::_MyVal(_Ptr));
    }

    Pointer operator->() const
    {
        return AddressOf(**this);
    }

    _MyIter& operator++() const
    {
        _Ptr = _MyList::NextNode(_Ptr);
        return (*this);
    }
    _MyIter operator++(int)
    {
        _MyIter _oTmp = *this;
        ++*this();
        return (_oTmp);
    }

    _MyIter& operator--() const
    {
        _Ptr = _MyList::PrevNode(_Ptr);
        return (*this);
    }

    _MyIter operator--(int)
    {
        _MyIter _oTmp = *this;
        --*this();
        return (_oTmp);
    }

    bool operator==(_MyIter const& _Right)
    {
        return (_Ptr = _Right._Ptr);
    }

    bool operator!=(_MyIter const& _Right)
    {
        return (!(*this == _Right));
    }

    _NodePtr _MyNode() const
    {
        return (_Ptr);
    }

    _NodePtr _Ptr;
};

template<typename _MyList>
class _ListUncheckIterator : public _ListUncheckedConstIterator<_MyList>
{
public:

    typedef _ListUncheckIterator<_MyList> _MyIter;
    typedef _ListUncheckedConstIterator<_MyList> _MyBase;
    typedef BidirectionalIteratorTag    IteratorCategory;
    typedef typename _MyList::_NodePtr _NodePtr;
    typedef typename _MyList::ValueType ValueType;
    typedef typename _MyList::DifferenceType DifferenceType;
    typedef typename _MyList::Pointer Pointer;
    typedef typename _MyList::Reference Reference;

    _ListUncheckIterator()
    {
    }

    _ListUncheckIterator(_NodePtr _pNode,_MyList const* _pList)
        :_MyBase(_pNode,_pList)
    {
    }

    Reference operator*() const
    {
        return((Reference)**(_MyBase*)this);
    }

    Pointer operator->() const
    {
        return AddressOf(**this);
    }

    _MyIter& operator++()
    {
        ++(*(_MyBase *)this);
        return (*this);
    }

    _MyIter operator++(int)
    {
        _MyIter _Tmp = *this;
        ++*this;
        return (_Tmp);
    }

    _MyIter& operator--()
    {
        --(*(_MyBase *)this);
        return (*this);
    }

    _MyIter operator--(int)
    {
        _MyIter _Tmp = *this;
        --*this;
        return (_Tmp);
    }

};


struct _ListNodeBase : AObject
{
    A_OBJECT(_ListNodeBase)
   _ListNodeBase *_pNext;
   _ListNodeBase *_pPrev;
};

template<typename _Ty>
struct _ListNode : _ListNodeBase
{
    A_OBJECT(_ListNode)
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
    A_OBJECT(_ListIterator)

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
    A_OBJECT(_ListConstIterator)

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
class _ListVal : public AObject
{
    A_OBJECT(_ListVal)
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

    _ListVal()
        :_oMyHead(),_nMySize(0)
    {
    }

    _NodeType _oMyHead;
    SizeType  _nMySize;
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

};

template<typename _Ty,typename _Alloc>
class _ListAlloc : public AObject
{
    A_OBJECT(_ListAlloc)
public:



    typedef _Ty                                     ValueType;
    typedef typename _Alloc::pointer                Pointer;
    typedef typename _Alloc::const_pointer          ConstPointer;
    typedef typename _Alloc::reference              Reference;
    typedef typename _Alloc::ConstReference         ConstReference;

    typedef _ListIterator<_Ty>                      Iterator;
    typedef _ListConstIterator<_Ty>                 ConstIterator;
    typedef std::reverse_iterator<Iterator>         ReverseIterator;
    typedef std::reverse_iterator<ConstIterator>    ConstReverseIterator;
    typedef size_t                                  SizeType;
    typedef _Alloc                                  AllocatorType;
    typedef _ListNode<_Ty>                          _NodeType;
    typedef _ListNode<_Ty>*                         _NodePtr;
    typedef _NodePtr&                               _NodePtrRef;
    typedef _ListAlloc<_Ty,_Alloc>                  _MyType;
    typedef _ListVal<_ListValTypes<_MyType>>        _ListValType;

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
        return (_GetVal()._nMySize);
    }

    _NodePtr _GetNewNode()
    {
        AllocatorType& rAlloc = _GetAlloc();
        return
    }

    _CompressedPair<_Alloc,_ListValType> _oPair;
};


template<typename _Ty,typename _Alloc>
class _ListBase : public _ListAlloc<_Ty,_Alloc>
{
    A_OBJECT(_ListBase)
public:
    typedef _ListAlloc<_Alloc>                          _MyBase;

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


};


template<typename _Ty,typename _Alloc = std::allocator<_Ty>>
class AList : public _ListBase<_Ty,_Alloc>
{
    A_TEMPLATE_OBJECT(AList,T)
public:

    static_assert(std::is_convertible(std::remove_reference<_Ty>::type,AObject),"component type must be subclass of AObject .");

public:

    AList()
    {
    }

    explicit AList(AllocatorType const& rAlloc = AllocatorType())
    {
    }

    AList(SizeType nCount,ValueType const& rValue = ValueType(),AllocatorType const& rAlloc = AllocatorType())
    {
    }

    explicit AList(SizeType nCount)
    {
    }

    explicit AList(SizeType nCount,AllocatorType const& rAlloc = AllocatorType())
    {
    }

    template<typename InputIt>
    AList(InputIt iFirst,InputIt rLast,AllocatorType const& rAlloc = AllocatorType())
    {
    }

    AList(_MyT const& rOther)
    {
    }

    AList(_MyT const& rOther,AllocatorType const& rAlloc = AllocatorType())
    {
    }

    AList(_MyT && rOther)
    {
    }

    AList(_MyT && rOther,AllocatorType const& rAlloc = AllocatorType())
    {
    }

    AList(std::initializer_list<T> oInit,AllocatorType const& rAlloc = AllocatorType())
    {
    }

    AList& operator=(_MyT const& rOther)
    {

    }

    AList& operator=(_MyT && rOther)
    {

    }

    AList operator=(std::initializer_list<T> oInit)
    {

    }

    ~AList()
    {
    }

public:

    void Assign(SizeType nCount,ValueType const& rValue)
    {

    }

    template<class InputIt>
    void Assign(InputIt iFirst,InputIt iLast)
    {

    }

    void Assign(std::initializer_list<T> oInit)
    {

    }

public:

    AllocatorType GetAllocator() const
    {

    }

public:

    Reference Front()
    {
        return *Begin();
    }

    ConstReference Front() const
    {
        return *Begin();
    }


    Reference Back()
    {

    }

    ConstReference Back() const
    {

    }

public:

    Iterator Begin()
    {
        return Iterator(_GetHead()->_pNext);
    }

    ConstIterator Begin() const
    {

    }

    ConstIterator CBegin() const
    {

    }

    Iterator End()
    {

    }

    ConstIterator End() const
    {

    }

    ConstIterator CEnd() const
    {

    }

public:

    ReverseIterator RBegin()
    {

    }

    ConstReverseIterator RBegin() const
    {

    }

    ConstReverseIterator CRBegin() const
    {

    }

    ReverseIterator REnd()
    {

    }

    ConstReverseIterator REnd() const
    {

    }

    ConstReverseIterator CREnd() const
    {

    }

public:

    bool Empty() const
    {

    }

    SizeType Size() const
    {

    }

    SizeType MaxSize() const
    {

    }

public:

    void Clear()
    {

    }

    Iterator Insert(Iterator iPos, ValueType const& rValue)
    {

    }

    Iterator Insert(ConstIterator iPos, ValueType const& rValue)
    {

    }

    Iterator Insert(ConstIterator iPos, ValueType &&rValue)
    {

    }

    void Insert(Iterator iPos, SizeType nCount,const ValueType &rValue)
    {

    }

    Iterator Insert(ConstIterator iPos, SizeType nCount,const ValueType &rValue)
    {

    }

    template<class InputIt>
    void Insert(Iterator iPos,InputIt iFirst,InputIt iLast)
    {

    }

    template<class InputIt>
    void Insert(ConstIterator iPos,InputIt iFirst,InputIt iLast)
    {

    }

    Iterator Insert(ConstIterator iPos, std::initializer_list<ValueType> oInit)
    {

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

    Iterator Erase(Iterator iFirst,Iterator iLast)
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

    void Swap(_MyT &rOther)
    {

    }

public:

    void Merge(_MyT &rOther)
    {

    }

    void Merge(_MyT &&rOther)
    {

    }

    template<typename Compare>
    void Merge(_MyT &rOther,Compare comp)
    {

    }

    template<typename Compare>
    void Merge(_MyT &&rOther,Compare comp)
    {

    }

public:

    void Splice(ConstIterator iPos,_MyT &rOther)
    {

    }

    void Splice(ConstIterator iPos, _MyT &&rOther)
    {

    }

private:

};

#endif // ALIST_H
