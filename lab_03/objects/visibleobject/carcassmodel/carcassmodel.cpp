#include "carcassmodel.h"

CarcassModel::CarcassModel(const CarcassModel &model)
{
    _data = model._data;
    _id = model._id;
}

Point CarcassModel::getCenter() const
{
    return _data->getCenter();
}

void CarcassModel::transform(const Matrix<double> &mtr, const Point &center)
{
    _data->transform(mtr, center);
}

void CarcassModel::transform(const Coeff &moveCoeff, const Coeff &scaleCoeff, const Coeff &rotateCoeff)
{
    move(moveCoeff);
    scale(scaleCoeff);
    rotate(rotateCoeff);
}

void CarcassModel::move(const Coeff &moveCoeff)
{
    _data->movePoints(moveCoeff);
}
void CarcassModel::scale(const Coeff &scaleCoeff)
{
    _data->scalePoints(scaleCoeff);
}
void CarcassModel::rotate(const Coeff &rotateCoeff)
{
    _data->rotatePoints(rotateCoeff);
}
