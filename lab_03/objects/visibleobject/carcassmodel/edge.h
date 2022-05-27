#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(const std::size_t firstVertex, const std::size_t secondVertex);
    Edge(const Edge &edge) = default;
    Edge(const Edge &&edge) noexcept;
    ~Edge() = default;

    std::size_t getFirst() const;
    std::size_t getSecond() const;

    void setFirst(const std::size_t index);
    void setSecond(const std::size_t index);

    Edge &operator=(const Edge &edge) = default;
    Edge &operator=(Edge &&edge) noexcept;

private:
    std::size_t _first;
    std::size_t _second;
};

#endif //EDGE_H
