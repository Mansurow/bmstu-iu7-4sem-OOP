#ifndef BASECAMERADIRECTOR_H
#define BASECAMERADIRECTOR_H


#include "basedirector.h"
#include "camerabuilder.h"

class BaseCameraDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<Camera> load(std::shared_ptr<BaseCameraBuilder> builder,
                                         std::string &fileName) = 0;
};

#endif // BASECAMERADIRECTOR_H
