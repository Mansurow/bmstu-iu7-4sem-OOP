#include <Facade.h>

Facade::Facade()
{
    _drawManager = ManagerSolution<DrawManagerCreator>().create();
    _loadManager = ManagerSolution<LoadManagerCreator>().create();
    _sceneManager = ManagerSolution<SceneManagerCreator>().create();
    _transformManager = ManagerSolution<TransformManagerCreator>().create();
    _modelLoadModerator = ModeratorSolution<ModelLoadModeratorCreator>().create();
    _sceneLoadModerator = ModeratorSolution<SceneLoadModeratorCreator>().create();;
    _drawCompositeAdapter = std::make_shared<DrawCompositeAdapter>(DrawCompositeAdapter());

    _loadManager->setModerator(_modelLoadModerator);
    _loadManager->setSceneModerator(_sceneLoadModerator);
    _drawManager->setAdapter(_drawCompositeAdapter);
}

void Facade::execute(BaseCommand &command)
{
    command.setManagers(_drawManager, _loadManager, _sceneManager, _transformManager,
                        _modelLoadModerator, _sceneLoadModerator,
                        _drawCompositeAdapter);
    _drawManager->setCamera( _sceneManager->getCamera());

    command.execute();
}
