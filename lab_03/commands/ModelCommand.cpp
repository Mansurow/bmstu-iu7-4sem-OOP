#include <QDebug>

#include <ModelCommand.h>


MoveModel::MoveModel(const double dx, const double dy, const double dz, const std::size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id)
{
    _method = &TransformManager::moveObject;
}

void MoveModel::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getObject(_id), _dx, _dy, _dz);
}



ScaleModel::ScaleModel(const double kx, const double ky, const double kz, const std::size_t id) :
    _kx(kx), _ky(ky), _kz(kz), _id(id)
{
    _method = &TransformManager::scaleObject;
}

void ScaleModel::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getObject(_id), _kx, _ky, _kz);
}



RotateModel::RotateModel(const double ox, const double oy, const double oz, const std::size_t id) :
        _ox(ox), _oy(oy), _oz(oz), _id(id)
{
    _method = &TransformManager::rotateObject;
}

void RotateModel::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getObject(_id), _ox, _oy, _oz);
}



TransformModel::TransformModel(const Matrix<double> &mtr, const std::size_t id) :
        _mtr(mtr), _id(id)
{
    _method = &TransformManager::transformObject;
}

void TransformModel::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getObject(_id), _mtr);
}



RemoveModel::RemoveModel(const std::size_t id) : _id(id)
{
    _method = &SceneManager::removeObject;
}

void RemoveModel::execute()
{
    ((*_sceneManager).*_method)(_id);
}



LoadModel::LoadModel(const ID &id, std::string &fileName) :
    _fileName(fileName), _id(id)
{
    _method = &LoadManager::load;
}

void LoadModel::execute()
{
    //auto model = _loadManager->load(_fileName);
    auto model = ((*_loadManager).*_method)(_fileName);
    (*_id) = _sceneManager->addObject(model);
}
