#include <CarcassModel.h>

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
