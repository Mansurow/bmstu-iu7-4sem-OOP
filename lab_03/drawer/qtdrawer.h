#ifndef QTDRAWER_H
#define QTDRAWER_H


#include <QGraphicsScene>

#include "basedrawer.h"


class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = delete;
    explicit QtDrawer(QGraphicsScene *scene);
    QtDrawer(const QtDrawer &drawer);

    void drawLine(const Point &fpoint, const Point &spoint) override;
    void clearScene() override;

private:
    QGraphicsScene *_scene;
};

#endif // QTDRAWER_H
