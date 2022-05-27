#include "composite.h"

Composite::Composite(std::shared_ptr<BaseObject> &element)
{
    _objects.push_back(element);
    updateCenter();
}


Composite::Composite(const std::vector<std::shared_ptr<BaseObject>> &vector)
{
    _objects = vector;
    updateCenter();
}


bool Composite::add(const std::shared_ptr<BaseObject> &element)
{
    _objects.push_back(element);
    updateCenter();

    return true;
}


bool Composite::remove(const Iterator &iter)
{
    _objects.erase(iter);
    updateCenter();

    return true;
}

void Composite::updateCenter()
{
    _center = Point(0, 0, 0);
    size_t count = 0;

    for (const auto &object : _objects)
    {
        _center = _center + object->getCenter();
        count++;
    }

    _center = Point(_center.getX() / count,
                     _center.getY() / count,
                     _center.getZ() / count);
}

bool Composite::isVisible()
{
    return false;
}

bool Composite::isComposite()
{
    return true;
}

Point Composite::getCenter() const
{
    return _center;
}

void Composite::moveElemsToOrigin(const Point &center)
{
    Point diff = Point(0, 0, 0) - center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformElems(mtr);
    updateCenter();
}

void Composite::moveElemsToCenter(const Point &center)
{
    Point diff = center - _center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformElems(mtr);
    updateCenter();
}

void Composite::transformElems(const Matrix<double> &mtr)
{
    for (const auto &object : _objects)
    {
        object->updateCenter();
        object->transform(mtr, _center);
    }
}

void Composite::transform(const Matrix<double> &mtr, const Point &center)
{
    updateCenter();

    moveElemsToOrigin(center);
    transformElems(mtr);
    moveElemsToCenter(center);
}

void Composite::transform(const Coeff &moveCoeff, const Coeff &scaleCoeff, const Coeff &rotateCoeff)
{
    for (const auto &object : _objects)
        object->transform(moveCoeff, scaleCoeff, rotateCoeff);
}

void Composite::move(const Coeff &moveCoeff)
{
    for (const auto &object : _objects)
    {
        object->updateCenter();
        object->move(moveCoeff);
    }
}

void Composite::scale(const Coeff &scaleCoeff)
{
    for (const auto &object : _objects)
    {
        object->updateCenter();
        object->scale(scaleCoeff);
    }
}

void Composite::rotate(const Coeff &rotaeCoeff)
{
    for (const auto &object : _objects)
    {
        object->updateCenter();
        object->rotate(rotaeCoeff);
    }
}

Iterator Composite::begin()
{
    return _objects.begin();
}


Iterator Composite::end()
{
    return _objects.end();
}
