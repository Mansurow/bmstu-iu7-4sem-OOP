#ifndef CAMERALOADMODERATORCREATOR_H
#define CAMERALOADMODERATORCREATOR_H

#include "cameraloadmoderator.h"
#include "basecameradirector.h"

class CameraLoadModeratorCreator
{
public:
    std::shared_ptr<CameraLoadModerator> createModerator();

private:
    void createInstance();

    std::shared_ptr<CameraLoadModerator> _moderator;
};


#endif // CAMERALOADMODERATORCREATOR_H
