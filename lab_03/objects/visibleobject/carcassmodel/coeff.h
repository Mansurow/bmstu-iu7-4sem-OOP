#ifndef COEFF_H
#define COEFF_H

class Coeff
{
public:
    Coeff() = default;
    Coeff(double x, double y, double z)
    {
        _x = x;
        _y = y;
        _z = z;
    };

    ~Coeff() = default;

    double getX() const { return _x; };
    double getY() const { return _y; };
    double getZ() const { return _z; };

    void setX(const double &x) { _x = x; };
    void setY(const double &y) { _y = y; };
    void setZ(const double &z) { _z = z; };

private:
    double _x, _y, _z;
};

#endif // COEFF_H
