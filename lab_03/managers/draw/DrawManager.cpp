#include <DrawManager.h>
#include <BaseModel.h>
#include <Camera.h>

void DrawManager::setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter)
{
    _adapter = adapter;
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene)
{
    _adapter->setAdaptee(scene->getVisibleObjects());
    _adapter->request();
}
