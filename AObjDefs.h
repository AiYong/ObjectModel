#ifndef AOBJDEFS_H
#define AOBJDEFS_H

#define A_OBJECT(clazz) \
    friend class clazz##Accessor;\
    \

#define Annotation(...)

#define UnUsed(O) (void)O;

#endif // AOBJDEFS_H
