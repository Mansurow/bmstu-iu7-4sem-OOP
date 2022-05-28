#include <Edge.h>

Edge::Edge(const std::size_t firstPoint, const std::size_t secondPoint)
{
    setFirst(firstPoint);
    setSecond(secondPoint);
}

std::size_t Edge::getFirst() const
{
    return _first;
}

std::size_t Edge::getSecond() const
{
    return _second;
}

void Edge::setFirst(const std::size_t index)
{
    _first = index;
}

void Edge::setSecond(const std::size_t index)
{
    _second = index;
}
