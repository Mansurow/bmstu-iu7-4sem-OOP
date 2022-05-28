#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <BaseManager.h>
#include <Point.h>
#include <Composite.h>
#include <BaseObject.h>
#include <Scene.h>
#include <BaseDrawer.h>
#include <BaseAdapter.h>
#include <DrawCompositeAdapter.h>

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;

    ~DrawManager() = default;

    void setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter);

    void drawScene(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<DrawCompositeAdapter> _adapter;
};

#endif //DRAWMANAGER_H
