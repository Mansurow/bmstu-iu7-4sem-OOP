#ifndef BASESCENEDIRECTOR_H
#define BASESCENEDIRECTOR_H


#include "scenebuilder.h"

class BaseSceneDirector
{
public:
    virtual std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder,
                                        std::string &fileName) = 0;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder,
                            std::string &fileName) = 0;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder,
                             std::string &fileName) = 0;
};

#endif // BASESCENEDIRECTOR_H
