#ifndef BASELOADER_H
#define BASELOADER_H

#include <string>
#include <vector>

#include <Point.h>
#include <Edge.h>


class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t loadCount() = 0;
    virtual Point loadPoint() = 0;
    virtual std::vector<Point> loadPoints() = 0;
    virtual std::vector<Edge> loadEdges(int &amountPoint) = 0;
};

#endif // BASELOADER_H
