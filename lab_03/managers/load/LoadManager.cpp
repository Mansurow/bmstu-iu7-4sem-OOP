#include "loadmanager.h"

#include <QDebug>

std::shared_ptr<BaseObject> LoadManager::load(std::string &name)
{
    return _moderator->load(name);
}

std::shared_ptr<Scene> LoadManager::loadScene(std::string &name)
{
    return _sceneModerator->load(name);
}

void LoadManager::setModerator(std::shared_ptr<BaseLoadModerator> moderator)
{
    _moderator = moderator;
}

void LoadManager::setSceneModerator(std::shared_ptr<SceneLoadModerator> moderator)
{
    _sceneModerator = moderator;
}
