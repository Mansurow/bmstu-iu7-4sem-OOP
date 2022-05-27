#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include "basecommand.h"
#include "managersolution.h"
#include "drawmanagercreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"
#include "loadmanagercreator.h"
#include "moderatorsolution.h"
#include "modelloadmoderatorcreator.h"
#include "sceneloadmoderatorcreator.h"

class Facade
{
public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command);
private:
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
    std::shared_ptr<ModelLoadModerator> _modelLoadModerator;
    std::shared_ptr<SceneLoadModerator> _sceneLoadModerator;
    std::shared_ptr<DrawCompositeAdapter> _drawCompositeAdapter;
};

#endif //FACADE_H
