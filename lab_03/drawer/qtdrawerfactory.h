#ifndef QTDRAWERFACTORY_H
#define QTDRAWERFACTORY_H


#include "abstractdrawerfactory.h"
#include "qtdrawer.h"


class QtDrawerFactory : public AbstractDrawerFactory
{
public:
    explicit QtDrawerFactory(QGraphicsScene *scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    QGraphicsScene *_scene;
};

#endif // QTDRAWERFACTORY_H
