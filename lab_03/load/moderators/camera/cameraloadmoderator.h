#ifndef CAMERALOADMODERATOR_H
#define CAMERALOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basecameradirector.h"

class CameraLoadModerator : public BaseLoadModerator
{
public:
    explicit CameraLoadModerator(std::shared_ptr<BaseCameraDirector> director);
    ~CameraLoadModerator() = default;

    std::shared_ptr<BaseObject> load(std::string &fileName) override;

private:
    std::shared_ptr<BaseCameraBuilder> _builder;
    std::shared_ptr<BaseCameraDirector> _director;
};

#endif // CAMERALOADMODERATOR_H
