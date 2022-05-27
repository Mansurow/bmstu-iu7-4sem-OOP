#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include "point.h"


class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point &fpoint, const Point &spoint) = 0;
    virtual void clearScene() = 0;
};

#endif // BASEDRAWER_H
