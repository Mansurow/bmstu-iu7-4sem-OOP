#include "sceneloadmoderator.h"
#include "exceptions.h"


SceneLoadModerator::SceneLoadModerator(std::shared_ptr<BaseSceneDirector> director) :
    _builder(new SceneBuilder)
{
    _director = director;
}

std::shared_ptr<Scene> SceneLoadModerator::load(std::string &fileName)
{
    std::shared_ptr<Scene> scene;

    try
    {
        scene = _director->load(_builder, fileName);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }
    catch (std::exception &error)
    {
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    return scene;
}

void SceneLoadModerator::setDirector(std::shared_ptr<BaseSceneDirector> director)
{
    _director = director;
}
