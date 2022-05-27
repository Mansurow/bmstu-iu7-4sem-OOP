#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "scene.h"
#include "camera.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager &scene) = delete;
    SceneManager &operator = (const SceneManager &scene) = delete;

    ~SceneManager() = default;

    std::shared_ptr<Scene> getScene() const;
    std::shared_ptr<Camera> getCamera() const;

    void setScene(std::shared_ptr<Scene> scene);
    void setCamera(const std::size_t id);

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Scene> _scene;
};


#endif // SCENEMANAGER_H
