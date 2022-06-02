#include <ModelsCommand.h>

MoveModels::MoveModels(const std::shared_ptr<Composite> objects, const double dx, const double dy, const double dz) :
   _objects(objects), _dx(dx), _dy(dy), _dz(dz)
{
    _method = &TransformManager::moveObject;
}

void MoveModels::execute()
{
    ((*_transformManager).*_method)(_objects, _dx, _dy, _dz);
}


ScaleModels::ScaleModels(const std::shared_ptr<Composite> objects, const double kx, const double ky, const double kz) :
   _objects(objects), _kx(kx), _ky(ky), _kz(kz)
{
    _method = &TransformManager::scaleObject;
}

void ScaleModels::execute()
{
    ((*_transformManager).*_method)(_objects, _kx, _ky, _kz);
}


RotateModels::RotateModels(const std::shared_ptr<Composite> objects, const double ox, const double oy, const double oz) :
      _objects(objects), _ox(ox), _oy(oy), _oz(oz)
{
    _method = &TransformManager::rotateObject;
}

void RotateModels::execute()
{
    ((*_transformManager).*_method)(_objects, _ox, _oy, _oz);
}



TransformModels::TransformModels(const std::shared_ptr<Composite> objects, const Matrix<double> &mtr) :
        _objects(objects), _mtr(mtr)
{
    _method = &TransformManager::transformObject;
}

void TransformModels::execute()
{
    ((*_transformManager).*_method)(_objects, _mtr);
}
