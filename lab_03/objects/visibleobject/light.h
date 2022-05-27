#ifndef LIGHT_H
#define LIGHT_H

#include <visibleobject.h>
#include <lightadapter.h>

class Light: public VisibleObject
{
    friend class AdapterLight;
public:
    Light() = default;
};

#endif // LIGHT_H
