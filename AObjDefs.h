#ifndef AOBJDEFS_H
#define AOBJDEFS_H

#include <initializer_list>

#define A_OBJECT() \
public:\
    static void _Call(std::initializer_list<AObject*> _Args,size_t nIndex,size_t nOp);\
    AClass* GetClass() const;\
    \

#define RootObject()

#define Annotation(...)

#define UNUSED(O) (void)O;

#endif // AOBJDEFS_H
