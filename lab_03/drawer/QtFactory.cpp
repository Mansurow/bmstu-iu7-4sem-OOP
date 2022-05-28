#include "QtFactory.h"

QtFactory::QtFactory(QGraphicsScene *scene)
{
    _scene = scene;
}

std::unique_ptr<BaseDrawer> QtFactory::createDrawer()
{
    return std::unique_ptr<BaseDrawer>(new QtDrawer(_scene));
}
