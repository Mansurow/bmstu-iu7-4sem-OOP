#ifndef QTFACTORY_H
#define QTFACTORY_H


#include <AbstractFactory.h>
#include <QtDrawer.h>


class QtFactory : public AbstractFactory
{
public:
    explicit QtFactory(QGraphicsScene *scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    QGraphicsScene *_scene;
};

#endif // QTFACTORY_H
