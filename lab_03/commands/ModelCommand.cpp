#include <QDebug>

#include <ModelCommand.h>


MoveModel::MoveModel(const std::shared_ptr<BaseObject> object, const double dx, const double dy, const double dz) :
    _object(object), _dx(dx), _dy(dy), _dz(dz)
{
    _method = &TransformManager::moveObject;
}

void MoveModel::execute()
{
    ((*_transformManager).*_method)(_object, _dx, _dy, _dz);
}



ScaleModel::ScaleModel(const std::shared_ptr<BaseObject> object, const double kx, const double ky, const double kz) :
     _object(object), _kx(kx), _ky(ky), _kz(kz)
{
    _method = &TransformManager::scaleObject;
}

void ScaleModel::execute()
{
    ((*_transformManager).*_method)(_object, _kx, _ky, _kz);
}



RotateModel::RotateModel(const std::shared_ptr<BaseObject> object, const double ox, const double oy, const double oz) :
         _object(object), _ox(ox), _oy(oy), _oz(oz)
{
    _method = &TransformManager::rotateObject;
}

void RotateModel::execute()
{
    ((*_transformManager).*_method)(_object, _ox, _oy, _oz);
}



TransformModel::TransformModel(const std::shared_ptr<BaseObject> object, const Matrix<double> &mtr) :
         _object(object), _mtr(mtr)
{
    _method = &TransformManager::transformObject;
}

void TransformModel::execute()
{
    ((*_transformManager).*_method)(_object, _mtr);
}



RemoveModel::RemoveModel(const std::size_t id) : _id(id)
{
    _method = &SceneManager::removeObject;
}

void RemoveModel::execute()
{
    ((*_sceneManager).*_method)(_id);
}



AddModel::AddModel(ID &id, std::shared_ptr<BaseObject> object) : _id(id), _object(object)
{
    _method = &SceneManager::addObject;
}

void AddModel::execute()
{
    (*_id) = ((*_sceneManager).*_method)(_object);
}



LoadModel::LoadModel(std::shared_ptr<BaseObject> &object, std::string &fileName) :
    _object(object), _fileName(fileName)
{
    _method = &LoadManager::load;
}

void LoadModel::execute()
{
    _object = ((*_loadManager).*_method)(_fileName);
}
