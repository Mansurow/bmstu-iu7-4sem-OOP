#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include <BaseCameraBuilder.h>

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    void build() override;
    void buildLocation(const Point &location) override;
    bool isBuild() const override;

    std::shared_ptr<Camera> get() override;
};

#endif //CAMERABUILDER_H
