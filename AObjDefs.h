#ifndef AOBJDEFS_H
#define AOBJDEFS_H


#define A_OBJECT(Clazz) \
    friend class Clazz##Accessor;\
public:\
    virtual AClass* GetClass()\
    {\
        AClass::LoadForName(AString::FromLocaleString(#Clazz));\
    }\
    \

#define A_TEMPLATE_OBJECT(Clazz,Component)\
    friend class Clazz##Component##Accessor;\
public:\
    virtual AClass* GetClass()\
    {\
        AClass::LoadForName(AString::FromLocaleString(#Clazz) + AString::FromLocaleString("<") +\
        AString::FromLocalString(#Component) + AString::FromLocalString(">"));\
    }\
    \

#define RootObject()

#define Annotation(...)

#define UNUSED(O) (void)O;

#endif // AOBJDEFS_H
