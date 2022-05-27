#include "scenemanagercreator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::createManager() {
    if (nullptr == _manager)
        createInstance();

    return _manager;
}


void SceneManagerCreator::createInstance()
{
    static std::shared_ptr<SceneManager> manager(new SceneManager());
    _manager = manager;
}
