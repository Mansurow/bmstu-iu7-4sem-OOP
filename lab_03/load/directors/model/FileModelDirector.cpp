#include <FileModelDirector.h>
#include <Exceptions.h>
#include <ModelBuilder.h>


FileModelDirector::FileModelDirector()
{
    _loader = std::make_shared<FileCarcassModelLoader>();
}

FileModelDirector::FileModelDirector(std::shared_ptr<FileCarcassModelLoader> &loader)
{
    _loader = loader;
}

std::shared_ptr<CarcassModel> FileModelDirector::load(std::shared_ptr<BaseModelBuilder> builder,
                                                           std::string &fileName)
{
    _loader->open(fileName);

    builder->build();

    vector<Point> points = _loader->loadPoints();
    int amountPoints = points.size();

    std::vector<Edge> edges = _loader->loadEdges(amountPoints);
    int amountEdges = edges.size();

    for (int i = 0; i < amountPoints; i++)
        builder->buildPoint(points[i]);

    for (int i = 0; i < amountEdges; i++)
        builder->buildEdge(edges[i]);

    _loader->close();

    return builder->get();
}
