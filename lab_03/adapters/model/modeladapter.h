#ifndef MODELADAPTER_H
#define MODELADAPTER_H

#include "baseadapter.h"
#include "carcassmodel.h"

class CarcassModel;

class ModelAdapter: public BaseAdapter
{
public:
    virtual ~ModelAdapter() = default;

    virtual void setAdaptee(std::shared_ptr<CarcassModel> adaptee) { _adaptee = adaptee; }

    virtual void request() = 0;
protected:
    std::shared_ptr<CarcassModel> _adaptee;
};

#endif // MODELADAPTER_H
