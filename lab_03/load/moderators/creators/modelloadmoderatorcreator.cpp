#include "modelloadmoderatorcreator.h"
#include "modeldirector.h"

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void ModelLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<ModelLoadModerator> moderator;

    if (!moderator)
    {
        auto reader = std::shared_ptr<FileModelLoader>(new FileModelLoader());
        auto director = std::shared_ptr<BaseModelDirector>(new ModelDirector(reader));
        moderator = std::make_shared<ModelLoadModerator>(director);
    }

    _moderator = moderator;
}
