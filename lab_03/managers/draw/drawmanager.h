#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "point.h"
#include "composite.h"
#include "baseobject.h"
#include "scene.h"
#include "basedrawer.h"
#include "baseadapter.h"
#include "drawcompositeadapter.h"

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
