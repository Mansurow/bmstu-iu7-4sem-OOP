#include <FileCameraDirector.h>
#include <Exceptions.h>

FileCameraDirector::FileCameraDirector()
{
    _loader = std::make_shared<FileCarcassModelLoader>();
}

FileCameraDirector::FileCameraDirector(std::shared_ptr<FileCarcassModelLoader> &loader)
{
    _loader = loader;
}

std::shared_ptr<Camera> FileCameraDirector::load(std::shared_ptr<BaseCameraBuilder> builder,
                                                      std::string &fileName)
{
    _loader->open(fileName);

    builder->build();
    Point location = _loader->loadPoint();
    Point direction = _loader->loadPoint();
    builder->buildLocation(location, direction);

    _loader->close();

    return builder->get();
}
