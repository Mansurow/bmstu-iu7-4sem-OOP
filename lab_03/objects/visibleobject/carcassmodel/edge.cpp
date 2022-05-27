#include <edge.h>

Edge::Edge(const std::size_t firstPoint, const std::size_t secondPoint)
{
    setFirst(firstPoint);
    setSecond(secondPoint);
}

Edge::Edge(const Edge &&edge) noexcept
{
    setFirst(edge._first);
    setSecond(edge._second);

    edge.~Edge();
}

Edge &Edge::operator=(Edge &&edge) noexcept
{
    setFirst(edge._first);
    setSecond(edge._second);

    edge.~Edge();

    return (*this);
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
