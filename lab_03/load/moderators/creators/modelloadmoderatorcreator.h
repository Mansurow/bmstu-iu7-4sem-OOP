#ifndef MODELLOADMODERATORCREATOR_H
#define MODELLOADMODERATORCREATOR_H

#include "modelloadmoderator.h"

class ModelLoadModeratorCreator
{
public:
    std::shared_ptr<ModelLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<ModelLoadModerator> _moderator;
};

#endif // MODELLOADMODERATORCREATOR_H
