#ifndef FILEMODELDIRECTOR_H
#define FILEMODELDIRECTOR_H


#include <BaseModelDirector.h>
#include <FileCarcassModelLoader.h>

class FileModelDirector : public BaseModelDirector
{
public:
    FileModelDirector();
    explicit FileModelDirector(std::shared_ptr<FileCarcassModelLoader> &loader);

    ~FileModelDirector() override = default;

    std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder,
                                       std::string &fileName) override;

protected:
    std::shared_ptr<FileCarcassModelLoader> _loader;
};

#endif // FILEMODELDIRECTOR_H
