#include <cmath>

#include <Point.h>

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

Point::Point(const double x, const double y, const double z)
{
    setX(x);
    setY(y);
    setZ(z);
}


Point::Point(const Point &&point) noexcept
{
    setX(point._x);
    setY(point._y);
    setZ(point._z);

    point.~Point();
}


Point &Point::operator=(Point &&point) noexcept
{
    setX(point._x);
    setY(point._y);
    setZ(point._z);

    point.~Point();

    return *this;
}

double Point::getX() const
{
    return _x;
}

double Point::getY() const
{
    return _y;
}

double Point::getZ() const
{
    return _z;
}

void Point::setX(const double x)
{
    _x = x;
}

void Point::setY(const double y)
{
    _y = y;
}

void Point::setZ(const double z)
{
    _z = z;
}

bool Point::operator==(const Point &point) const noexcept
{
    return (point._x == _x) && (point._y == _y) && (point._z == _z);
}

bool Point::isEqual(const Point &point) const noexcept
{
    return *this == point;
}

bool Point::operator!=(const Point &point) const noexcept
{
    return !(*this == point);
}

bool Point::isNotEqual(const Point &point) const noexcept
{
    return !(*this == point);
}

Point Point::operator+(const Point &point) const
{
    Point d{*this};

    d.setX(d._x + point._x);
    d.setY(d._y + point._y);
    d.setZ(d._z + point._z);

    return d;
}

Point Point::operator-(const Point &point) const
{
    Point d{*this};

    d.setX(d._x - point._x);
    d.setY(d._y - point._y);
    d.setZ(d._z - point._z);

    return d;
}


void Point::transform(const Matrix<double> &mtr)
{
    Matrix<double> cur_location = {{_x, _y, _z, 1}};
    Matrix<double> new_location = cur_location * mtr;

    _x = new_location[0][0];
    _y = new_location[0][1];
    _z = new_location[0][2];
}

Point Point::getCenter() const
{
    return *this;
}

Point Point::getAbsVertex(const Point &center)
{
    return (*this) + center;
}
