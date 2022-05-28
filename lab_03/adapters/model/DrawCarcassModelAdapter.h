#ifndef DRAWCARCASSMODELADAPTER_H
#define DRAWCARCASSMODELADAPTER_H

#include <ModelAdapter.h>
#include <Camera.h>
#include <BaseDrawer.h>

class Camera;

class DrawCarcassModelAdapter : public ModelAdapter
{
public:
    void setCamera(std::shared_ptr<Camera> camera);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);

    virtual void request() override;

    Point getProjection(const Point &point);

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif // DRAWCARCASSMODELADAPTER_H
