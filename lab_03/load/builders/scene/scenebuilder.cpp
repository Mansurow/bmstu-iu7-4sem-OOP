#include "scenebuilder.h"


void SceneBuilder::build()
{
    _scene = std::make_shared<Scene>();
}


void SceneBuilder::buildObject(const std::shared_ptr<BaseObject> &object)
{
    _scene->addObject(object);
}


bool SceneBuilder::isBuild() const
{
    return nullptr != _scene;
}


std::shared_ptr<Scene> SceneBuilder::get()
{
    return _scene;
}
