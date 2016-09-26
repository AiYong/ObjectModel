#ifndef ALIST_H
#define ALIST_H

#include "AObject.h"
#include <list>

template<typename T>
class AList : public AObject
{
public:

    typedef std::list<T> _MyCT;

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

public:

    AList();

private:

    _MyCT m_oContainer;

};

#endif // ALIST_H
