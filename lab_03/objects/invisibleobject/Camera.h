#ifndef CAMERA_H
#define CAMERA_H

#include "InVisibleObject.h"
#include "DrawCarcassModelAdapter.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    Camera() = default;
    Camera(const Point &location, const Point &direction) : _location(location), _direction(direction) { }
    ~Camera() override = default;

    virtual Point getCenter() const override;
    void transform(const Matrix<double> &mtr, const Point &center) override;
private:
    Point _location;
    Point _direction;
};


#endif //CAMERA_H
