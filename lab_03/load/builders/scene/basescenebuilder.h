#ifndef BASESCENEBUILDER_H
#define BASESCENEBUILDER_H


#include "scene.h"
#include "basebuilder.h"

class BaseSceneBuilder : public BaseBuilder
{
public:
    BaseSceneBuilder() = default;
    ~BaseSceneBuilder() = default;

    virtual void build() override = 0;
    virtual void buildObject(const std::shared_ptr<BaseObject> &object) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<Scene> get() = 0;

protected:
    std::shared_ptr<Scene> _scene;
};

#endif // BASESCENEBUILDER_H
