#ifndef AOBJDEFS_H
#define AOBJDEFS_H


#define A_OBJECT(clazz) \
    friend class clazz##Accessor;\
public:\
    virtual AClass* GetClass()\
    {\
        AClass::LoadForName(AString::FromLocaleString(#clazz));\
    }\
    \

#define RootObject()

#define Annotation(...)

#define UNUSED(O) (void)O;

#endif // AOBJDEFS_H
