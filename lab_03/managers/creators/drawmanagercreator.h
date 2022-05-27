#ifndef DRAWMANAGERCREATOR_H
#define DRAWMANAGERCREATOR_H

#include "drawmanager.h"

class DrawManagerCreator
{
public:
    std::shared_ptr<DrawManager> createManager();

private:
    void createInstance();

    std::shared_ptr<DrawManager> _manager;
};

#endif //DRAWMANAGERCREATOR_H
