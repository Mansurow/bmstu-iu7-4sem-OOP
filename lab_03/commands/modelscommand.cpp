#include "modelscommand.h"


MoveModels::MoveModels(const double dx, const double dy, const double dz) :
    _dx(dx), _dy(dy), _dz(dz) { }

void MoveModels::execute()
{
    _transformManager->moveObject(_scene->getVisibleObjects(), _dx, _dy, _dz);
}



ScaleModels::ScaleModels(const double kx, const double ky, const double kz) :
    _kx(kx), _ky(ky), _kz(kz) { }

void ScaleModels::execute()
{
    _transformManager->scaleObject(_scene->getVisibleObjects(), _kx, _ky, _kz);
}



RotateModels::RotateModels(const double ox, const double oy, const double oz) :
        _ox(ox), _oy(oy), _oz(oz) { }

void RotateModels::execute()
{
    _transformManager->rotateObject(_scene->getVisibleObjects(), _ox, _oy, _oz);
}



TransformModels::TransformModels(const Matrix<double> &mtr) :
        _mtr(mtr) { }

void TransformModels::execute()
{
    _transformManager->transformObject(_scene->getVisibleObjects(), _mtr);
}
