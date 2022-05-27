#ifndef MODELLOADMODERATOR_H
#define MODELLOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basemodeldirector.h"
#include "basemodelbuilder.h"

class ModelLoadModerator : public BaseLoadModerator
{
public:
    ModelLoadModerator() = default;
    explicit ModelLoadModerator(std::shared_ptr<BaseModelDirector> director);

    ~ModelLoadModerator() = default;

    std::shared_ptr<BaseObject> load(std::string &fileName) override;

private:
    std::shared_ptr<BaseModelBuilder> _builder;
    std::shared_ptr<BaseModelDirector> _director;
};

#endif // MODELLOADMODERATOR_H
