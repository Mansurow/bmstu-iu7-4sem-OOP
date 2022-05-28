#include <CameraLoadModeratorCreator.h>
#include <FileCameraDirector.h>

std::shared_ptr<CameraLoadModerator> CameraLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void CameraLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<CameraLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseCameraDirector> director;
        director = std::shared_ptr<BaseCameraDirector>(new FileCameraDirector);
        moderator = std::make_shared<CameraLoadModerator>(director);
    }

    _moderator = moderator;
}


