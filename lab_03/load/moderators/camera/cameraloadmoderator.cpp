#include "cameraloadmoderator.h"
#include "exceptions.h"
#include "camerabuilder.h"


CameraLoadModerator::CameraLoadModerator(std::shared_ptr<BaseCameraDirector> director) :
    _builder(new CameraBuilder)
{
    _director = director;
}

std::shared_ptr<BaseObject> CameraLoadModerator::load(std::string &fileName)
{
    std::shared_ptr<Camera> camera_sh_ptr;

    try
    {
        camera_sh_ptr = _director->load(_builder, fileName);
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

    return std::shared_ptr<BaseObject>(camera_sh_ptr);
}
