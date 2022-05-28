#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <memory>
#include <cstddef>

#include <BaseCommand.h>

using ID = std::shared_ptr<std::size_t>;

class CameraCommand : public BaseCommand { };

class AddCamera: public CameraCommand
{
    using Action = size_t(SceneManager::*)(const Point &location);
public:
    AddCamera(const ID & id, const Point &location);

    virtual void execute() override;

private:
    ID _id;
    Point _location;
    Action _method;
};


class RemoveCamera: public CameraCommand
{
    using Action = void(SceneManager::*)(const size_t id);
public:
    RemoveCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
    Action _method;
};


class MoveCamera: public CameraCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &dx, const double &dy, const double &dz);
public:
    MoveCamera(const double dx, const double dy, const double dz, const size_t id);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
    Action _method;
};


class SetCamera: public CameraCommand
{
    using Action = void(SceneManager::*)(size_t id);
public:
    explicit SetCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
    Action _method;
};

#endif //CAMERACOMMAND_H
