#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <BaseManager.h>
#include <Scene.h>
#include <Camera.h>

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager &scene) = delete;
    SceneManager &operator = (const SceneManager &scene) = delete;

    ~SceneManager() = default;

    std::shared_ptr<Scene> getScene() const;
    std::shared_ptr<Camera> getCamera() const;
    std::shared_ptr<BaseObject> getObject(const size_t id) { return _scene->getObject(id); };

    size_t addCamera(const Point &location) { return _scene->addCamera(location); };

    size_t addObject(const shared_ptr<BaseObject> &object)
    {
        return _scene->addObject(object);
    };

    void removeObject(const size_t id)
    {
        Iterator objIt = _scene->getObjectIter(id);
        _scene->deleteObject(objIt);
    };

    void setScene(std::shared_ptr<Scene> scene);
    void setCamera(const std::size_t id);

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Scene> _scene;
};


#endif // SCENEMANAGER_H
