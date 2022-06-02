#include <QDebug>

#include <CameraCommand.h>

AddCamera::AddCamera(const ID &id, const Point &location, const Point &direction) :
    _id(id), _location(location), _direction(direction) {
    _method = &SceneManager::addCamera;
}

void AddCamera::execute()
{
    (*_id) = ((*_sceneManager).*_method)(_location, _direction);
}


RemoveCamera::RemoveCamera(const std::size_t id) : _id(id)
{
    _method = &SceneManager::removeObject;
}

void RemoveCamera::execute()
{
    ((*_sceneManager).*_method)(_id);
}


MoveCamera::MoveCamera(const std::shared_ptr<Camera> camera, const double dx, const double dy, const double dz) :
    _camera(camera), _dx(dx), _dy(dy), _dz(dz)
{
    _method = &TransformManager::moveObject;
}

void MoveCamera::execute()
{
    ((*_transformManager).*_method)(_camera, _dx, _dy, _dz);
}


SetCamera::SetCamera(const std::size_t id) : _id(id)
{
    _method = &SceneManager::setCamera;
}

void SetCamera::execute()
{
    ((*_sceneManager).*_method)(_id);
}
