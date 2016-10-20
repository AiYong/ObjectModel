#ifndef AOBJECT_H
#define AOBJECT_H

#include <functional>

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

public:

    /**
     * @brief 返回对象的哈希值
     * 哈希值在std::hash模板中使用
     * @return
     */
    virtual size_t HashValue() const;

};

namespace std {

/**
 *特化hash模板，是的AObject及其子类可作为标准容器的Key
 */
template<>
struct hash<AObject*>
{
    size_t operator ()(AObject const* pObj)
    {
        return pObj->HashValue();
    }
};

}

#endif // AOBJECT_H
