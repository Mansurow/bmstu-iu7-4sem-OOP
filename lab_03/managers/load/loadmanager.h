#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

#include "basemanager.h"
#include "basemodel.h"
#include "baseloadmoderator.h"
#include "sceneloadmoderator.h"
#include "modelloadmoderator.h"

class LoadManager : BaseManager
{
public:
    LoadManager() = default;
    LoadManager(const LoadManager &manager) = delete;
    LoadManager &operator = (const LoadManager &manager) = delete;

    ~LoadManager() = default;

    std::shared_ptr<BaseObject> load(std::string &name);
    std::shared_ptr<Scene> loadScene(std::string &name);
    void setModerator(std::shared_ptr<BaseLoadModerator> moderator);
    void setSceneModerator(std::shared_ptr<SceneLoadModerator> moderator);

private:
    std::shared_ptr<BaseLoadModerator> _moderator;
    std::shared_ptr<SceneLoadModerator> _sceneModerator;
};

#endif // LOADMANAGER_H
