#include <SceneCommand.h>

ClearScene::ClearScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer)
{
    _method = &DrawManager::clearScene;
}

void ClearScene::execute()
{
    ((*_drawManager).*_method)(_drawer);
}



GetMainCamera::GetMainCamera(std::shared_ptr<Camera> &camera) : _camera(camera)
{
    _method = &SceneManager::getCamera;
}

void GetMainCamera::execute()
{
    _camera = ((*_sceneManager).*_method)();
}



GetSceneObjects::GetSceneObjects(std::shared_ptr<Composite> &objects) : _objects(objects)
{
    _method = &SceneManager::getVisibleObjects;
}

void GetSceneObjects::execute()
{
    _objects = ((*_sceneManager).*_method)();
}



GetSceneObject::GetSceneObject(std::shared_ptr<BaseObject> &object, const std::size_t id) : _object(object), _id(id)
{
    _method = &SceneManager::getObject;
}

void GetSceneObject::execute()
{
    _object = ((*_sceneManager).*_method)(_id);
}



DrawScene::DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer) : _scene(scene), _drawer(drawer)
{
    _method = &DrawManager::drawScene;
}

void DrawScene::execute()
{
    ((*_drawManager).*_method)(_scene, _drawer);
}



SetScene::SetScene(std::shared_ptr<Scene> scene) : _scene(scene)
{
    _method = &SceneManager::setScene;
}

void SetScene::execute()
{
    ((*_sceneManager).*_method)(_scene);
}



GetScene::GetScene(std::shared_ptr<Scene> &scene) : _scene(scene)
{
    _method = &SceneManager::getScene;
}

void GetScene::execute()
{
    _scene = ((*_sceneManager).*_method)();
}



LoadScene::LoadScene(std::shared_ptr<Scene> &scene, const std::string fileName) : _scene(scene), _fileName(fileName)
{
    _method = &LoadManager::loadScene;
}

void LoadScene::execute()
{
    _scene = ((*_loadManager).*_method)(_fileName);
}
