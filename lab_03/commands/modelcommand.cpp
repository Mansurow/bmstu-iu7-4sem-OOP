#include <QDebug>

#include "modelcommand.h"


MoveModel::MoveModel(const double dx, const double dy, const double dz, const std::size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) { }

void MoveModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->moveObject(model, _dx, _dy, _dz);
}



ScaleModel::ScaleModel(const double kx, const double ky, const double kz, const std::size_t id) :
    _kx(kx), _ky(ky), _kz(kz), _id(id) { }

void ScaleModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->scaleObject(model, _kx, _ky, _kz);
}



RotateModel::RotateModel(const double ox, const double oy, const double oz, const std::size_t id) :
        _ox(ox), _oy(oy), _oz(oz), _id(id) { }

void RotateModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->rotateObject(model, _ox, _oy, _oz);
}



TransformModel::TransformModel(const Matrix<double> &mtr, const std::size_t id) :
        _mtr(mtr), _id(id) { }

void TransformModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->transformObject(model, _mtr);
}



RemoveModel::RemoveModel(const std::size_t id) : _id(id) { }

void RemoveModel::execute()
{
    Iterator objIt = _scene->getObjectIter(_id);
    _scene->removeObject(objIt);
}



LoadModel::LoadModel(const ID &id, std::string &fileName) :
    _fileName(fileName), _id(id) { }

void LoadModel::execute()
{
    auto model = _loadManager->load(_fileName);
    (*_id) = _scene->addObject(model);
}
