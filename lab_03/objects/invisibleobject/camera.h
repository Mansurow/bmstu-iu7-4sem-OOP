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
    virtual void transform(const Coeff &moveCoeff, const Coeff &scaleCoeff, const Coeff &rotateCoeff) override
    {
        move(moveCoeff);
        scale(scaleCoeff);
        rotate(rotateCoeff);
    }

    void move(const Coeff &moveCoeff) override { move(moveCoeff); };
    void scale(const Coeff &scaleCoeff) override { scale(scaleCoeff); };
    void rotate(const Coeff &rotateCoeff) override { rotate(rotateCoeff); };

private:
    Point _location;
};


#endif //CAMERA_H
