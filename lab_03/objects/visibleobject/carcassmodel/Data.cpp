#include <Data.h>

Data::Data(std::vector<Point> &points, std::vector<Edge> &edges) :
    _center{ }, _points(points), _edges(edges) { }


Data::Data(std::vector<Point> &points, std::vector<Edge> &edges,
                               Point &center):
    _center(center), _points(points), _edges(edges) { }

const std::vector<Point> &Data::getPoints() const
{
    return _points;
}

const std::vector<Edge> &Data::getEdges() const
{
    return _edges;
}

const Point Data::getCenter() const
{
    return _center;
}

void Data::addPoint(const Point &point)
{
    _points.push_back(point);
    updateCenter();
}

void Data::addEdge(const Edge &edge)
{
    _edges.push_back(edge);
}

void Data::updateCenter()
{
    _center = Point(0, 0, 0);
    size_t count = 0;

    for (const auto &element : _points)
    {
        _center = _center + element.getCenter();
        count++;
    }

    _center = Point(_center.getX() / count,
                     _center.getY() / count,
                     _center.getZ() / count);
}

void Data::moveVertexesToOrigin(const Point &center)
{
    Point diff = Point(0, 0, 0) - center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformPoints(mtr);
    updateCenter();
}

void Data::movePointsToCenter(const Point &center)
{
    Point diff = center - Point(0, 0, 0);

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformPoints(mtr);
    updateCenter();
}

void Data::transformPoints(const Matrix<double> &mtr)
{
    for (auto &vertex : _points)
        vertex.transform(mtr);
}

void Data::transform(const Matrix<double> &mtr, const Point &center)
{
    updateCenter();

    moveVertexesToOrigin(center);
    transformPoints(mtr);
    movePointsToCenter(center);
}
