#ifndef CAMERADIRECTOR_H
#define CAMERADIRECTOR_H


#include "basecameradirector.h"
#include "filemodelreader.h"

class CameraDirector : public BaseCameraDirector
{
public:
    CameraDirector();
    explicit CameraDirector(std::shared_ptr<FileModelLoader> &reader);

    ~CameraDirector() override = default;

    std::shared_ptr<Camera> load(std::shared_ptr<BaseCameraBuilder> builder,
                                 std::string &fileName) override;

protected:
    std::shared_ptr<FileModelLoader> _reader;
};

#endif // CAMERADIRECTOR_H
