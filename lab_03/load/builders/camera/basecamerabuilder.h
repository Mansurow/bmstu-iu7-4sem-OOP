#ifndef BASECAMERABUILDER_H
#define BASECAMERABUILDER_H


#include "camera.h"
#include "basebuilder.h"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual void build() override = 0;
    virtual void buildLocation(const Point &location) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<Camera> get() = 0;

protected:
    std::shared_ptr<Camera> _camera;
};

#endif // BASECAMERABUILDER_H
