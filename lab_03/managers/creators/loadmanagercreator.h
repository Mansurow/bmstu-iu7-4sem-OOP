#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H

#include <memory>

#include "loadmanager.h"


class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> createManager();

private:
    void createInstance();

    std::shared_ptr<LoadManager> _manager;
};

#endif //LOADMANAGERCREATOR_H
