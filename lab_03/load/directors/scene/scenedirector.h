#ifndef SCENEDIRECTOR_H
#define SCENEDIRECTOR_H


#include "basescenedirector.h"
#include "filemodelreader.h"

class SceneDirector : public BaseSceneDirector
{
public:
    SceneDirector();
    explicit SceneDirector(std::shared_ptr<FileModelLoader> &reader);
    ~SceneDirector() = default;

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder,
                                std::string &fileName) override;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder,
                    std::string &fileName) override;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder,
                     std::string &fileName) override;

    std::shared_ptr<FileModelLoader> _reader;
};

#endif // SCENEDIRECTOR_H
