#ifndef FILESCENEDIRECTOR_H
#define FILESCENEDIRECTOR_H


#include <BaseSceneDirector.h>
#include <FileCarcassModelLoader.h>

class FileSceneDirector : public BaseSceneDirector
{
public:
    FileSceneDirector();
    explicit FileSceneDirector(std::shared_ptr<FileCarcassModelLoader> &loader);
    ~FileSceneDirector() = default;

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder,
                                std::string &fileName) override;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder,
                    std::string &fileName) override;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder,
                     std::string &fileName) override;

    std::shared_ptr<FileCarcassModelLoader> _loader;
};

#endif // FILESCENEDIRECTOR_H
