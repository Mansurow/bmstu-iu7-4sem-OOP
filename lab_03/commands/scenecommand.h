#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <memory>
#include <string>

#include "basecommand.h"

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
public:
    DrawScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};



class LoadScene : public SceneCommand
{
public:
    LoadScene(const std::string fileName);

    virtual void execute() override;

private:
    std::string _fileName;

};

#endif //SCENECOMMAND_H
