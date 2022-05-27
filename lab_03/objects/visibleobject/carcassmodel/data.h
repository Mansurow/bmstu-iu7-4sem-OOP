#ifndef DATA_H
#define DATA_H

#include <vector>

#include "point.h"
#include "edge.h"

class Data
{
public:
    Data() = default;
    Data(std::vector<Point> &points, std::vector<Edge> &edges);
    Data(std::vector<Point> &points, std::vector<Edge> &edges, Point &center);

    ~Data() = default;

    const std::vector<Point> &getPoints() const;
    const std::vector<Edge> &getEdges() const;
    const Point getCenter() const;

    void addPoint(const Point &point);
    void addEdge(const Edge &edge);
    void updateCenter();

    void movePointsToOrigin(const Point &center);
    void movePointsToCenter(const Point &center);
    void transformPoints(const Matrix<double> &mtr);
    void transform(const Matrix<double> &mtr, const Point &center);

    void movePoints(const Coeff &moveCoeff);
    void movePoints(const double dx, const double dy, const double dz);

    void scalePoints(const Coeff &scaleCoeff);
    void scalePoints(const double kx, const double ky, const double kz);

    void rotatePoints(const Coeff &rotateCoeff);
    void rotatePoints(const double rx, const double ry, const double rz);
private:
    Point _center;
    std::vector<Point> _points;
    std::vector<Edge> _edges;
};


#endif //DATA_H
