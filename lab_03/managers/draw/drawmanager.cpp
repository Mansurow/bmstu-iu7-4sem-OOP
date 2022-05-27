#include "drawmanager.h"
#include "basemodel.h"
#include "camera.h"

void DrawManager::setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter)
{
    _adapter = adapter;
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene)
{
    _adapter->setAdaptee(scene->getVisibleObjects());
    _adapter->request();
}
