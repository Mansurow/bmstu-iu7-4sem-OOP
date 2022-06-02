#include <DrawManager.h>
#include <BaseModel.h>
#include <Camera.h>

void DrawManager::setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter)
{
    _adapter = adapter;
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer)
{
    _adapter->setDrawer(drawer);
    _adapter->setAdaptee(scene->getVisibleObjects());
    _adapter->request();
}
