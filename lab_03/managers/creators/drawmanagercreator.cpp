#include "drawmanagercreator.h"


std::shared_ptr<DrawManager> DrawManagerCreator::createManager()
{
    if (nullptr == _manager)
        createInstance();

    return _manager;
}


void DrawManagerCreator::createInstance()
{
    static std::shared_ptr<DrawManager> manager(new DrawManager());
    _manager = manager;
}
