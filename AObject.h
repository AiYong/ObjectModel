#ifndef AOBJECT_H
#define AOBJECT_H

#include "AObjDefs.h"

class AClass;

/**
 * @brief AObject类
 * 该类是继承体系的根类，要使用反射系统，其他类型必须继承于该类，并使用A_OBJECT宏声明，
 */
class AObject
{
    A_OBJECT()
public:

    /**
     * @brief 构造函数
     */
    AObject();

    /**
     * @brief 析构函数
     */
    virtual ~AObject();

};

#endif // AOBJECT_H
