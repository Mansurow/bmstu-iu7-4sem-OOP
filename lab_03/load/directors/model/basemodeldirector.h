#ifndef BASEMODELDIRECTOR_H
#define BASEMODELDIRECTOR_H


#include "basedirector.h"
#include "modelbuilder.h"

class BaseModelDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder,
                                               std::string &fileName) = 0;
};

#endif // BASEMODELDIRECTOR_H
