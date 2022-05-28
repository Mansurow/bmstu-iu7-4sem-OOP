#ifndef DATA_H
#define DATA_H

#include <vector>

#include "Point.h"
#include "Edge.h"

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

    void moveVertexesToOrigin(const Point &center);
    void movePointsToCenter(const Point &center);
    void transformPoints(const Matrix<double> &mtr);
    void transform(const Matrix<double> &mtr, const Point &center);

private:
    Point _center;

    std::vector<Point> _points;
    std::vector<Edge> _edges;
};


#endif //DATA_H
