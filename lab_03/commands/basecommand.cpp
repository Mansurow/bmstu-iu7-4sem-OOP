#include "basecommand.h"

void BaseCommand::setManagers(std::shared_ptr<DrawManager> drawManager,
                              std::shared_ptr<LoadManager> loadManager,
                              std::shared_ptr<SceneManager> sceneManager,
                              std::shared_ptr<TransformManager> transformManager,
                              std::shared_ptr<ModelLoadModerator> modelLoadModerator,
                              std::shared_ptr<SceneLoadModerator> sceneLoadModerator,
                              std::shared_ptr<DrawCompositeAdapter> drawCompositeAdapter)
{
    _drawManager = drawManager;
    _loadManager = loadManager;
    _sceneManager = sceneManager;
    _transformManager = transformManager;
    _modelLoadModerator = modelLoadModerator;
    _sceneLoadModerator = sceneLoadModerator;
    _drawCompositeAdapter = drawCompositeAdapter;
}

void BaseCommand::setScene(std::shared_ptr<Scene> scene)
{
    _scene = scene;
}
