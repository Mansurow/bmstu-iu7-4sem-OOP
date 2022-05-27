#include <cmath>

#include <point.h>

static inline double toRadian(double angle)
{
    return angle * M_PI / 180.0;
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

Point Point::operator*(const Point &point) const
{
    Point newPoint(*this);

    newPoint._x = newPoint._x * point._x;
    newPoint._y = newPoint._y * point._y;
    newPoint._z = newPoint._z * point._z;

    return newPoint;
}

Point Point::operator/(const Point &point) const
{
    Point newPoint(*this);
    // исключение деление на нуль
    newPoint._x = newPoint._x / point._x;
    newPoint._y = newPoint._y / point._y;
    newPoint._z = newPoint._z / point._z;

    return newPoint;
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

Point Point::getAbsPoint(const Point &center)
{
    return (*this) + center;
}

void Point::move(const Coeff &moveCoeff)
{
    _x += moveCoeff.getX();
    _y += moveCoeff.getY();
    _z += moveCoeff.getZ();
}

void Point::scale(const Point &center, const Coeff &scaleCoeff)
{
    _x = (_x - center._x) * scaleCoeff.getX() + center._x;
    _y = (_y - center._y) * scaleCoeff.getY() + center._y;
    _z = (_z - center._z) * scaleCoeff.getZ() + center._z;
}

void Point::rotate(const Point &center, const Coeff &rotateCoeff)
{
    (*this) = (*this) - center;

    rotate_yz(rotateCoeff.getX());
    rotate_xz(rotateCoeff.getY());
    rotate_xy(rotateCoeff.getZ());

    (*this) = (*this) + center;
}

void Point::rotate_yz(double angle)
{
    double degAngle = toRadian(angle);

    double tmpy = _y;
    double tmpz = _z;

    _y = tmpy * cos(degAngle) - tmpz * sin(degAngle);
    _z = tmpy * sin(degAngle) + tmpz * cos(degAngle);
}

void Point::rotate_xz(double angle)
{
    double degAngle = toRadian(angle);

    double tmpx = _x;
    double tmpz = _z;

    _x = tmpx * cos(degAngle) - tmpz * sin(degAngle);
    _z = tmpx * sin(degAngle) + tmpz * cos(degAngle);
}

void Point::rotate_xy(double angle)
{
    double degAngle = toRadian(angle);

    double tmpx = _x;
    double tmpy = _y;

    _x = tmpx * cos(degAngle) - tmpy * sin(degAngle);
    _y = tmpx * sin(degAngle) + tmpy * cos(degAngle);
}
