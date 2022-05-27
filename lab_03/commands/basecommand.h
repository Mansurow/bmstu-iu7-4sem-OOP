#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "drawmanager.h"
#include "loadmanager.h"
#include "scenemanager.h"
#include "transformmanager.h"
#include "cameraloadmoderator.h"
#include "modelloadmoderator.h"
#include "sceneloadmoderator.h"
#include "drawcompositeadapter.h"


class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void setManagers(std::shared_ptr<DrawManager> drawManager,
                             std::shared_ptr<LoadManager> loadManager,
                             std::shared_ptr<SceneManager> sceneManager,
                             std::shared_ptr<TransformManager> transformManager,
                             std::shared_ptr<ModelLoadModerator> modelLoadModerator,
                             std::shared_ptr<SceneLoadModerator> sceneLoadModerator,
                             std::shared_ptr<DrawCompositeAdapter> drawCompositeAdapter);

    virtual void setScene(std::shared_ptr<Scene> scene);

    virtual void execute() = 0;

protected:
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
    std::shared_ptr<ModelLoadModerator> _modelLoadModerator;
    std::shared_ptr<SceneLoadModerator> _sceneLoadModerator;
    std::shared_ptr<DrawCompositeAdapter> _drawCompositeAdapter;
    std::shared_ptr<Scene> _scene;
};


#endif //BASECOMMAND_H
