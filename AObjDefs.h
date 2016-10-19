#ifndef AOBJDEFS_H
#define AOBJDEFS_H

#include <initializer_list>

/**
 *@brief 对象访问器主模板
 */
template<typename T>
class AObjectAccessor
{
};


#define A_OBJECT() \
    template<typename T>\
    friend class AObjectAccessor;\
public:\
    static AClass* GetClass() const;\
    \

#define A_ANNOTATION()\
    template<typename T>\
    friend class AObjectAccessor;\
public:\
    static AClass* GetClass() const;\
    \

#define ANNOTATION_CLASS(...)   __attribute__((annotate(#__VA_ARGS__)))

#ifdef __ROC__
#define ANNOTATION(Class,...)   ANNOTATION_CLASS(Class,__VA_ARGS__)
#else
#define ANNOTATION(...)
#endif


#define UNUSED(O) (void)O;

#endif // AOBJDEFS_H
