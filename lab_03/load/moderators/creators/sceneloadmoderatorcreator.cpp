#include "sceneloadmoderatorcreator.h"
#include "scenedirector.h"

std::shared_ptr<SceneLoadModerator> SceneLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void SceneLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<SceneLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseSceneDirector> director;
        director = std::shared_ptr<BaseSceneDirector>(new SceneDirector);
        moderator = std::make_shared<SceneLoadModerator>(director);
    }

    _moderator = moderator;
}


