#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T15:29:09
#
#-------------------------------------------------

QT       -= core gui

TARGET = ObjectModel
TEMPLATE = app

DEFINES += OBJECTMODEL_LIBRARY

SOURCES += \
    AObject.cpp \
    AClass.cpp \
    AMethod.cpp \
    AField.cpp \
    AConstructor.cpp \
    ADestructor.cpp \
    AAnnotation.cpp \
    AString.cpp \
    AParameter.cpp \
    ALong.cpp \
    AInteger.cpp \
    ADouble.cpp \
    AFloat.cpp \
    AShort.cpp \
    AChar.cpp \
    AUnsignedLong.cpp \
    AUnsignedInteger.cpp \
    AUnsignedShort.cpp \
    AClassLoader.cpp \
    Impl/AObjectAccessor.cpp \
    Impl/AClassClass.cpp \
    Impl/AObjectClass.cpp \
    ANumber.cpp

HEADERS += \
    AObject.h \
    AClass.h \
    AMethod.h \
    AField.h \
    AConstructor.h \
    ADestructor.h \
    AAnnotation.h \
    AString.h \
    AList.h \
    AParameter.h \
    ALong.h \
    AInteger.h \
    ADouble.h \
    AFloat.h \
    AObjDefs.h \
    AShort.h \
    AChar.h \
    AUnsignedLong.h \
    AUnsignedInteger.h \
    AUnsignedShort.h \
    AClassLoader.h \
    Impl/AObjectAccessor.h \
    Impl/AClassClass.h \
    Impl/AObjectClass.h \
    ANumber.h \
    AArray.h \
    AVector.h \
    AMap.h \
    ASet.h \
    AXUtility.h \
    ATypeTraits.h \
    AMemory.h \
    AUtility.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
