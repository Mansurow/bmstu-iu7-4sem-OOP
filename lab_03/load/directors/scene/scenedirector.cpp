#include "scenedirector.h"
#include "cameradirector.h"
#include "modeldirector.h"
#include "exceptions.h"

SceneDirector::SceneDirector()
{
    _reader = std::make_shared<FileModelLoader>();
}

SceneDirector::SceneDirector(std::shared_ptr<FileModelLoader> &reader)
{
    _reader = reader;
}

std::shared_ptr<Scene> SceneDirector::load(std::shared_ptr<SceneBuilder> builder,
                                                    std::string &fileName)
{
    _reader->open(fileName);

    builder->build();

    loadModels(builder, fileName);
    loadCameras(builder, fileName);

    _reader->close();

    return builder->get();
}

void SceneDirector::loadModels(std::shared_ptr<SceneBuilder> builder,
                                        std::string &fileName)
{
    size_t modelsCount = _reader->loadCount();

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (size_t i = 0; i < modelsCount; i++)
    {
        auto model = ModelDirector(_reader).load(modBuilder, fileName);
        builder->buildObject(model);
    }
}

void SceneDirector::loadCameras(std::shared_ptr<SceneBuilder> builder,
                                         std::string &fileName)
{
    size_t camsCount = _reader->loadCount();

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (size_t i = 0; i < camsCount; i++)
    {
        auto camera = CameraDirector(_reader).load(camBuilder, fileName);
        builder->buildObject(camera);
    }
}
