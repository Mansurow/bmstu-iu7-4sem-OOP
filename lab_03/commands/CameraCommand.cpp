#include <QDebug>

#include <CameraCommand.h>

AddCamera::AddCamera(const ID &id, const Point &location) :
    _id(id), _location(location) {
    _method = &SceneManager::addCamera;
}

void AddCamera::execute()
{
    (*_id) = ((*_sceneManager).*_method)(_location);
}


RemoveCamera::RemoveCamera(const std::size_t id) : _id(id)
{
    _method = &SceneManager::removeObject;
}

void RemoveCamera::execute()
{
    ((*_sceneManager).*_method)(_id);
}



MoveCamera::MoveCamera(const double dx, const double dy, const double dz, const size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id)
{
    _method = &TransformManager::moveObject;
}

void MoveCamera::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getObject(_id), _dx, _dy, _dz);;
}

SetCamera::SetCamera(const std::size_t id) : _id(id)
{
    _method = &SceneManager::setCamera;
}

void SetCamera::execute()
{
    ((*_sceneManager).*_method)(_id);
}
