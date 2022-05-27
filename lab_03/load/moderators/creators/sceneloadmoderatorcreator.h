#ifndef SCENELOADMODERATORCREATOR_H
#define SCENELOADMODERATORCREATOR_H

#include "sceneloadmoderator.h"

class SceneLoadModeratorCreator
{
public:
    std::shared_ptr<SceneLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<SceneLoadModerator> _moderator;
};


#endif //SCENELOADMODERATORCREATOR_H
