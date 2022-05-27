#include "cameradirector.h"
#include "exceptions.h"

CameraDirector::CameraDirector()
{
    _reader = std::make_shared<FileModelLoader>();
}

CameraDirector::CameraDirector(std::shared_ptr<FileModelLoader> &reader)
{
    _reader = reader;
}

std::shared_ptr<Camera> CameraDirector::load(std::shared_ptr<BaseCameraBuilder> builder,
                                                      std::string &fileName)
{
    _reader->open(fileName);

    builder->build();
    Point location = _reader->loadPoint();
    builder->buildLocation(location);

    _reader->close();

    return builder->get();
}
