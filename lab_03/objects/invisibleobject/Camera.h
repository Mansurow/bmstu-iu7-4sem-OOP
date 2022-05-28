#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"
#include "drawcarcassmodeladapter.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    Camera() = default;
    Camera(const Point &location) : _location(location) { }
    ~Camera() override = default;

    virtual Point getCenter() const override;
    void transform(const Matrix<double> &mtr, const Point &center) override;
private:
    Point _location;
};


#endif //CAMERA_H