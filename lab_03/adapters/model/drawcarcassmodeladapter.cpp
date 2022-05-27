#include "drawcarcassmodeladapter.h"

void DrawCarcassModelAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCarcassModelAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

Point DrawCarcassModelAdapter::getProjection(const Point &vertex)
{
    Point projection = vertex;

    projection.setX(projection.getX() + _camera->_location.getX());
    projection.setY(projection.getY() + _camera->_location.getY());

    return projection;
}

void DrawCarcassModelAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        auto points = _adaptee->_data->getPoints();
        auto edges = _adaptee->_data->getEdges();
        auto center = _adaptee->_data->getCenter();

        for (auto edge : edges)
        {
            _drawer->drawLine(getProjection(points.at(edge.getFirst() - 1)).getAbsPoint(center),
                              getProjection(points.at(edge.getSecond() - 1)).getAbsPoint(center));
        }
    }
}
