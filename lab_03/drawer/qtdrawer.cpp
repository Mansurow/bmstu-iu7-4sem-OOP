#include "qtdrawer.h"

QtDrawer::QtDrawer(QGraphicsScene *scene)
{
    _scene = scene;
}


QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    _scene = drawer._scene;
}


void QtDrawer::drawLine(const Point &fpoint, const Point &spoint)
{
    _scene->addLine(fpoint.getX(), fpoint.getY(), spoint.getX(), spoint.getY());
}


void QtDrawer::clearScene()
{
    _scene->clear();
}
