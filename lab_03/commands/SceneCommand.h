#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <memory>
#include <string>

#include <BaseCommand.h>

class SceneCommand : public BaseCommand { };

class ClearScene : public SceneCommand
{
    using Action = void(DrawManager::*)(std::shared_ptr<BaseDrawer> drawer);
public:
    ClearScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    Action _method;
};

class GetMainCamera : public SceneCommand {
    using Action = std::shared_ptr<Camera>(SceneManager::*)() const;
public:
    explicit GetMainCamera(std::shared_ptr<Camera> &camera);

    ~GetMainCamera() override = default;

    void execute() override;

private:
    std::shared_ptr<Camera> &_camera;
    Action _method;
};

class GetSceneObjects:public SceneCommand
{
    using Action = std::shared_ptr<Composite>(SceneManager::*)();
public:
    GetSceneObjects(std::shared_ptr<Composite> &objects);

    virtual void execute() override;
private:
    std::shared_ptr<Composite> &_objects;

    Action _method;
};

class GetSceneObject: public SceneCommand
{
    using Action = std::shared_ptr<BaseObject>(SceneManager::*)(const std::size_t id);
public:
    GetSceneObject(std::shared_ptr<BaseObject> &object, const std::size_t id);

    virtual void execute() override;
private:
    std::shared_ptr<BaseObject> &_object;
    std::size_t _id;
    Action _method;
};

class DrawScene : public SceneCommand
{
    using Action = void(DrawManager::*)(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer);
public:
    DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<BaseDrawer> _drawer;
    Action _method;
};

class SetScene: public SceneCommand
{
    using Action = void(SceneManager::*)(std::shared_ptr<Scene> &scene);
public:
    SetScene(std::shared_ptr<Scene> scene);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> _scene;
    Action _method;
};

class GetScene: public SceneCommand
{
    using Action = std::shared_ptr<Scene>(SceneManager::*)() const;
public:
    explicit GetScene(std::shared_ptr<Scene> &scene);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> &_scene;
    Action _method;
};

class LoadScene : public SceneCommand
{
    using Action = std::shared_ptr<Scene>(LoadManager::*)(std::string &name);
public:
    LoadScene(std::shared_ptr<Scene> &scene, const std::string fileName);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> &_scene;
    std::string _fileName;
    Action _method;
};

#endif //SCENECOMMAND_H
