#ifndef ABSTRACTDRAWERFACTORY_H
#define ABSTRACTDRAWERFACTORY_H

#include <memory>
#include "basedrawer.h"

class AbstractDrawerFactory
{
public:
    virtual std::unique_ptr<BaseDrawer> createDrawer() = 0;
};

#endif // ABSTRACTDRAWERFACTORY_H
