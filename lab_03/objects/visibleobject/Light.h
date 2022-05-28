#ifndef LIGHT_H
#define LIGHT_H

#include <VisibleObject.h>
#include <LightAdapter.h>

class Light: public VisibleObject
{
    friend class AdapterLight;
public:
    Light() = default;
    ~Light() = default;
};

#endif // LIGHT_H
