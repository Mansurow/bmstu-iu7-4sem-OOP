#ifndef MODELDIRECTOR_H
#define MODELDIRECTOR_H


#include "basemodeldirector.h"
#include "filemodelreader.h"

class ModelDirector : public BaseModelDirector
{
public:
    ModelDirector();
    explicit ModelDirector(std::shared_ptr<FileModelLoader> &reader);

    ~ModelDirector() override = default;

    std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder,
                                       std::string &fileName) override;

protected:
    std::shared_ptr<FileModelLoader> _reader;
};

#endif // MODELDIRECTOR_H
