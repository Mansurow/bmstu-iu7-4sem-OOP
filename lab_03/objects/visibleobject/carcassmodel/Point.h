#ifndef POINT_H
#define POINT_H

#include "matrix.h"

class Point
{
public:
    Point() = default;
    Point(const double x, const double y, const double z);

    Point(const Point &point) = default;
    Point(const Point &&point) noexcept;

    Point &operator=(const Point &point) = default;
    Point &operator=(Point &&point) noexcept;

    ~Point() = default;

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double const x);
    void setY(double const y);
    void setZ(double const z);

    bool operator==(const Point &point) const noexcept;
    bool isEqual(const Point &point) const noexcept;

    bool operator!=(const Point &point) const noexcept;
    bool isNotEqual(const Point &point) const noexcept;

    Point operator+(const Point &point)  const;
    Point operator-(const Point &point)  const;

    Point getAbsVertex(const Point &center);

    Point getCenter() const;
    void transform(const Matrix<double> &mtr);

private:
    double _x;
    double _y;
    double _z;
};

#endif // POINT_H
