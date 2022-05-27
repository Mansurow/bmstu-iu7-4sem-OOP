#ifndef SCENEMANAGERCREATOR_H
#define SCENEMANAGERCREATOR_H

#include <memory>
#include "scenemanager.h"

class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> createManager();

private:
    void createInstance();

    std::shared_ptr<SceneManager> _manager;
};

#endif // SCENEMANAGERCREATOR_H
