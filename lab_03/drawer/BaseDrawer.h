#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include <Point.h>

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point &vertex1, const Point &vertex2) = 0;
    virtual void clearScene() = 0;
};

#endif // BASEDRAWER_H
