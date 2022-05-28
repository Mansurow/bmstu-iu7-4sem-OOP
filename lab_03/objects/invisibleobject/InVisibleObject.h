#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "BaseObject.h"

class InvisibleObject : public BaseObject
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool isVisible() override { return false; }
};

#endif //INVISIBLEOBJECT_H
