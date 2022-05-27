#include "loadmanagercreator.h"

std::shared_ptr<LoadManager> LoadManagerCreator::createManager()
{
    if (nullptr == _manager)
        createInstance();

    return _manager;
}

void LoadManagerCreator::createInstance()
{
    static std::shared_ptr<LoadManager> manager(new LoadManager());

    _manager = manager;
}
