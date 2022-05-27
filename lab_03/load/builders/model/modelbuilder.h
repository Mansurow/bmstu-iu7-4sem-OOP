#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <basemodelbuilder.h>

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    void build() override;
    void buildPoint(const Point &point) override;
    void buildEdge(const Edge &edge) override;
    bool isBuild() const override;

    std::shared_ptr<CarcassModel> get() override;
};

#endif //BUILDER_MODEL_H
