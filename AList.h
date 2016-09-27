#ifndef ALIST_H
#define ALIST_H

#include "AObject.h"
#include <list>
#include <type_traits>


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

    AList():m_oContainer()
    {
    }

    explicit AList(AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(rAlloc)
    {
    }

    AList(SizeType nCount,ValueType const& rValue = ValueType(),AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(nCount,rValue,rAlloc)
    {
    }

    explicit AList(SizeType nCount)
        :m_oContainer(nCount)
    {
    }

    explicit AList(SizeType nCount,AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(nCount,rAlloc)
    {
    }

    template<typename InputIt>
    AList(InputIt iFirst,InputIt rLast,AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(iFirst,rLast,rAlloc)
    {
    }

    AList(_MyT const& rOther)
        :m_oContainer(rOther.m_oContainer)
    {
    }

    AList(_MyT const& rOther,AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(rOther.m_oContainer,rAlloc)
    {
    }

    AList(_MyT && rOther)
        :m_oContainer(std::forward<_MyCT>(rOther.m_oContainer))
    {
    }

    AList(_MyT && rOther,AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(std::forward<_MyCT>(rOther.m_oContainer),rAlloc)
    {
    }

    AList(std::initializer_list<T> oInit,AllocatorType const& rAlloc = AllocatorType())
        :m_oContainer(oInit,rAlloc)
    {
    }

    AList& operator=(_MyT const& rOther)
    {
        m_oContainer = rOther.m_oContainer;
    }

    AList& operator=(_MyT && rOther)
    {
        m_oContainer = std::forward<_MyT>(rOther.m_oContainer);
    }

    AList operator=(std::initializer_list<T> oInit)
    {
        m_oContainer = oInit;
    }

    ~AList()
    {
    }

public:

    void Assign(SizeType nCount,ValueType const& rValue)
    {
        m_oContainer.assign(nCount,rValue);
    }

    template<class InputIt>
    void Assign(InputIt iFirst,InputIt iLast)
    {
        m_oContainer.assign(iFirst,iLast);
    }

    void Assign(std::initializer_list<T> oInit)
    {
        m_oContainer.assign(oInit);
    }

public:

    AllocatorType GetAllocator() const
    {
        return m_oContainer.get_allocator();
    }

public:

    Reference Front()
    {
        return m_oContainer.front();
    }

    ConstReference Front() const
    {
        return m_oContainer.front();
    }


    Reference Back()
    {
        return m_oContainer.back();
    }

    ConstReference Back() const
    {
        return m_oContainer.back();
    }

public:

    Iterator Begin()
    {
        return m_oContainer.begin();
    }

    ConstIterator Begin() const
    {
        return m_oContainer.begin();
    }

    ConstIterator CBegin() const
    {
        return m_oContainer.cbegin();
    }

    Iterator End()
    {
        return m_oContainer.end();
    }

    ConstIterator End() const
    {
        return m_oContainer.end();
    }

    ConstIterator CEnd() const
    {
        return m_oContainer.cend();
    }

public:

    ReverseIterator RBegin()
    {
        return m_oContainer.rbegin();
    }

    Con

private:

    _MyCT m_oContainer;

};

#endif // ALIST_H
