#include <FileSceneDirector.h>
#include <FileCameraDirector.h>
#include <FileModelDirector.h>
#include <Exceptions.h>

FileSceneDirector::FileSceneDirector()
{
    _loader = std::make_shared<FileCarcassModelLoader>();
}

FileSceneDirector::FileSceneDirector(std::shared_ptr<FileCarcassModelLoader> &loader)
{
    _loader = loader;
}

std::shared_ptr<Scene> FileSceneDirector::load(std::shared_ptr<SceneBuilder> builder,
                                                    std::string &fileName)
{
    _loader->open(fileName);

    builder->build();

    loadModels(builder, fileName);
    loadCameras(builder, fileName);

    _loader->close();

    return builder->get();
}

void FileSceneDirector::loadModels(std::shared_ptr<SceneBuilder> builder,
                                        std::string &fileName)
{
    size_t modelsCount = _loader->loadCount();

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (size_t i = 0; i < modelsCount; i++)
    {
        auto model = FileModelDirector(_loader).load(modBuilder, fileName);
        builder->buildObject(model);
    }
}

void FileSceneDirector::loadCameras(std::shared_ptr<SceneBuilder> builder,
                                         std::string &fileName)
{
    size_t camsCount = _loader->loadCount();

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (size_t i = 0; i < camsCount; i++)
    {
        auto camera = FileCameraDirector(_loader).load(camBuilder, fileName);
        builder->buildObject(camera);
    }
}
