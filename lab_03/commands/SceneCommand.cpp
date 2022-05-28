#include <SceneCommand.h>

ClearScene::ClearScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) {}

void ClearScene::execute()
{
    _drawer->clearScene();
}



DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer)
{
    _method = &DrawManager::drawScene;
}

void DrawScene::execute()
{
    _drawCompositeAdapter->setDrawer(_drawer);
    ((*_drawManager).*_method)(_sceneManager->getScene());
}



LoadScene::LoadScene(const std::string fileName) : _fileName(fileName)
{
    _method = &LoadManager::loadScene;
}

void LoadScene::execute()
{
    auto scene = ((*_loadManager).*_method)(_fileName);
    _sceneManager->setScene(scene);
}
