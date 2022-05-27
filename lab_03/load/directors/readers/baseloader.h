#ifndef BASELOADER_H
#define BASELOADER_H

#include <string>
#include <vector>

#include "point.h"
#include "edge.h"


class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t loadCount() = 0;
    virtual Point loadPoint() = 0;
    virtual Edge loadEdge(int &amountPoints) = 0;
    virtual std::vector<Point> loadPoints() = 0;
    virtual std::vector<Edge> loadEdges(int &amountPoints) = 0;
};

#endif // BASELOADER_H
