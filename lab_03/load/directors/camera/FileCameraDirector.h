#ifndef FILECAMERADIRECTOR_H
#define FILECAMERADIRECTOR_H


#include <BaseCameraDirector.h>
#include <FileCarcassModelLoader.h>

class FileCameraDirector : public BaseCameraDirector
{
public:
    FileCameraDirector();
    explicit FileCameraDirector(std::shared_ptr<FileCarcassModelLoader> &loader);

    ~FileCameraDirector() override = default;

    std::shared_ptr<Camera> load(std::shared_ptr<BaseCameraBuilder> builder,
                                 std::string &fileName) override;

protected:
    std::shared_ptr<FileCarcassModelLoader> _loader;
};

#endif // FILECAMERADIRECTOR_H
