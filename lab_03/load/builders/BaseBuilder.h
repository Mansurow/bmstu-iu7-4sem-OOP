#ifndef BASEBUILDER_H
#define BASEBUILDER_H


class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual void build() = 0;
    virtual bool isBuild() const = 0;
};

#endif //BASEBUILDER_H
