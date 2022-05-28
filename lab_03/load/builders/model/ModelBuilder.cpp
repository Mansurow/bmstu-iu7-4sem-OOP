#include <ModelBuilder.h>

void ModelBuilder::build()
{
    _model = std::make_shared<Data>();
}


void ModelBuilder::buildPoint(const Point &point)
{
    if (!isBuild()) { }

    _model->addPoint(point);
}


void ModelBuilder::buildEdge(const Edge &edge)
{
    if (!isBuild()) { }

    _model->addEdge(edge);
}


bool ModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<CarcassModel> ModelBuilder::get()
{
    return std::make_shared<CarcassModel>(CarcassModel(_model));
}
