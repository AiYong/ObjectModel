#ifndef AOBJDEFS_H
#define AOBJDEFS_H

#define A_OBJECT(clazz) \
    friend class clazz##AClass;\
    friend class clazz##AField;\
    friend class clazz##AMethod;\
    friend class clazz##AConstructor;\
    friend class clazz##ADestructor;\
    \

#define Annotation(...)


#endif // AOBJDEFS_H
