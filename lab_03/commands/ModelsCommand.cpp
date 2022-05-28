#include <ModelsCommand.h>

MoveModels::MoveModels(const double dx, const double dy, const double dz) :
    _dx(dx), _dy(dy), _dz(dz)
{
    _method = &TransformManager::moveObject;
}

void MoveModels::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getScene()->getVisibleObjects(), _dx, _dy, _dz);
}


ScaleModels::ScaleModels(const double kx, const double ky, const double kz) :
    _kx(kx), _ky(ky), _kz(kz)
{
    _method = &TransformManager::scaleObject;
}

void ScaleModels::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getScene()->getVisibleObjects(), _kx, _ky, _kz);
}


RotateModels::RotateModels(const double ox, const double oy, const double oz) :
        _ox(ox), _oy(oy), _oz(oz)
{
    _method = &TransformManager::rotateObject;
}

void RotateModels::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getScene()->getVisibleObjects(), _ox, _oy, _oz);
}



TransformModels::TransformModels(const Matrix<double> &mtr) :
        _mtr(mtr)
{
    _method = &TransformManager::transformObject;
}

void TransformModels::execute()
{
    ((*_transformManager).*_method)(_sceneManager->getScene()->getVisibleObjects(), _mtr);
}
