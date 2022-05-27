#include "modeldirector.h"
#include "exceptions.h"
#include "modelbuilder.h"


ModelDirector::ModelDirector()
{
    _reader = std::make_shared<FileModelLoader>();
}

ModelDirector::ModelDirector(std::shared_ptr<FileModelLoader> &loader)
{
    _reader = loader;
}

std::shared_ptr<CarcassModel> ModelDirector::load(std::shared_ptr<BaseModelBuilder> builder,
                                                           std::string &fileName)
{
    _reader->open(fileName);

    builder->build();

    vector<Point> points = _reader->loadPoints();
    int amountPoints = points.size();

    std::vector<Edge> edges = _reader->loadEdges(amountPoints);
    int amountEdges = edges.size();

    for (int i = 0; i < amountPoints; i++)
        builder->buildPoint(points[i]);

    for (int i = 0; i < amountEdges; i++)
        builder->buildEdge(edges[i]);

    _reader->close();

    return builder->get();
}
