#ifndef SCENELOADMODERATOR_H
#define SCENELOADMODERATOR_H

#include "basescenedirector.h"
#include "scenebuilder.h"

class SceneLoadModerator
{
public:
    SceneLoadModerator() = default;
    explicit SceneLoadModerator(std::shared_ptr<BaseSceneDirector> director);

    ~SceneLoadModerator() = default;

    std::shared_ptr<Scene> load(std::string &fileName);
    virtual void setDirector(std::shared_ptr<BaseSceneDirector> director);

private:
    std::shared_ptr<SceneBuilder> _builder;
    std::shared_ptr<BaseSceneDirector> _director;
};

#endif //SCENELOADMODERATOR_H
