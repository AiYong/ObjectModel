#ifndef ALIST_H
#define ALIST_H

#include "AObject.h"
#include <list>
#include <type_traits>

#include "AXUtility.h"

template<typename _MyList,
         typename _Base = _IteratorBase0>
class _ListUncheckedConstIterator : public

template<typename T>
class AList : public AObject
{
public:

    typedef std::list<T> _MyCT;
    typedef AList<T> _MyT;
    typedef typename _MyCT::allocator_type AllocatorType;
    typedef typename _MyCT::size_type SizeType;
    typedef typename _MyCT::difference_type DifferenceType;
    typedef typename _MyCT::pointer Pointer;
    typedef typename _MyCT::const_pointer ConstPointer;
    typedef typename _MyCT::reference Reference;
    typedef typename _MyCT::const_reference ConstReference;
    typedef typename _MyCT::value_type ValueType;
    typedef typename _MyCT::const_iterator ConstIterator;
    typedef typename _MyCT::iterator Iterator;
    typedef typename _MyCT::reverse_iterator ReverseIterator;
    typedef typename _MyCT::const_reverse_iterator ConstReverseIterator;

    static_assert(std::is_convertible(T*,AObject*),"component type must be subclass of AObject .");

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

    }

    ConstReference Front() const
    {

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
