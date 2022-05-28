#ifndef LIGHTADAPTER_H
#define LIGHTADAPTER_H

#include <BaseAdapter.h>
#include <Light.h>

class LightAdapter: BaseAdapter
{
public:
    LightAdapter(shared_ptr<Light> adaptee): _adaptee(adaptee) {};

    virtual void request() override;

    virtual ~LightAdapter() = default;
private:
    shared_ptr<Light> _adaptee;
};

#endif // LIGHTADAPTER_H
