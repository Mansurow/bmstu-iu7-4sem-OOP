#include "qtdrawerfactory.h"

QtDrawerFactory::QtDrawerFactory(QGraphicsScene *scene)
{
    _scene = scene;
}

std::unique_ptr<BaseDrawer> QtDrawerFactory::createDrawer()
{
    return std::unique_ptr<BaseDrawer>(new QtDrawer(_scene));
}
