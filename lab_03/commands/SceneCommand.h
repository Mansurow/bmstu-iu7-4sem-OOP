#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <memory>
#include <string>

#include <BaseCommand.h>

class SceneCommand : public BaseCommand { };

class ClearScene : public SceneCommand
{
public:
    ClearScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};



class DrawScene : public SceneCommand
{
    using Action = void(DrawManager::*)(std::shared_ptr<Scene> scene);
public:
    DrawScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    Action _method;
};



class LoadScene : public SceneCommand
{
    using Action = std::shared_ptr<Scene>(LoadManager::*)(std::string &name);
public:
    LoadScene(const std::string fileName);

    virtual void execute() override;

private:
    std::string _fileName;
    Action _method;
};

#endif //SCENECOMMAND_H
