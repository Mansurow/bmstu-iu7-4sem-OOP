#ifndef COMPOSITEADAPTER_H
#define COMPOSITEADAPTER_H

#include "baseadapter.h"
#include "composite.h"

class Composite;

class CompositeAdapter: public BaseAdapter
{
public:
    virtual ~CompositeAdapter() = default;

    void setAdaptee(std::shared_ptr<Composite> adaptee) { _adaptee = adaptee; };

    virtual void request() = 0;
protected:
    std::shared_ptr<Composite>  _adaptee;
};

#endif // COMPOSITEADAPTER_H
