#include <cmath>

#include "TransformManager.h"

void TransformManager::moveObject(const std::shared_ptr <BaseObject> &object,
                                  const double &dx,
                                  const double &dy,
                                  const double &dz)
{
    Matrix<double> mtr = {{ 1,  0,  0, 0},
                          { 0,  1,  0, 0},
                          { 0,  0,  1, 0},
                          {dx, dy, dz, 1}};

    object->updateCenter();
    object->transform(mtr, object->getCenter());
}


void TransformManager::scaleObject(const std::shared_ptr <BaseObject> &object,
                                   const double &kx,
                                   const double &ky,
                                   const double &kz)
{
    Matrix<double> mtr = {{kx,  0,  0, 0},
                          { 0, ky,  0, 0},
                          { 0,  0, kz, 0},
                          { 0,  0,  0, 1}};

    object->updateCenter();
    object->transform(mtr, object->getCenter());
}


void TransformManager::rotateObject(const std::shared_ptr <BaseObject> &object,
                                   const double &ox,
                                   const double &oy,
                                   const double &oz)
{
    Matrix<double> mtr_ox = {{1,        0,        0,        0},
                             {0,     cos(ox), -sin(ox),     0},
                             {0,     sin(ox),  cos(ox),     0},
                             {0,        0,        0,        1}};

    Matrix<double> mtr_oy = {{ cos(oy), 0, sin(oy), 0},
                             {    0,    1,    0,    0},
                             {-sin(oy), 0, cos(oy), 0},
                             {    0,    0,    0,    1}};

    Matrix<double> mtr_oz = {{ cos(oz), -sin(oz),     0,        0},
                             { sin(oz),  cos(oz),     0,        0},
                             {    0,        0,        1,        0},
                             {    0,        0,        0,        1}};

    object->updateCenter();
    object->transform(mtr_ox * mtr_oy * mtr_oz, object->getCenter());
}

void TransformManager::transformObject(const std::shared_ptr<BaseObject> &object,
                                       const Matrix<double> &mtr)
{
    object->updateCenter();
    object->transform(mtr, object->getCenter());
}
