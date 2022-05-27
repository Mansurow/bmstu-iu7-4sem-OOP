#include <iterator>

#include "scene.h"
#include "composite.h"

#include <QDebug>

Scene::Scene() : _visibleObjects(new Composite), _invisibleObjects(new Composite) { }

std::size_t Scene::addObject(const std::shared_ptr<BaseObject> &object)
{
    if (object->isVisible())
        _visibleObjects->add(object);
    else
        _invisibleObjects->add(object);

    return object->getId();
}

std::size_t Scene::addCamera(const Point &location)
{
    auto camera = std::make_shared<Camera>(Camera(location));
    _invisibleObjects->add(camera);

    return camera->getId();
}

void Scene::removeObject(Iterator &iter)
{
    if ((*iter)->isVisible())
        _visibleObjects->remove(iter);
    else
        _invisibleObjects->remove(iter);
}

Iterator Scene::getObjectIter(const std::size_t id)
{
    auto iter = vbegin();
    for (; iter != vend() && (*iter)->getId() != id; ++iter);

    if (iter == vend())
    {
        iter = ibegin();
        for (; iter != iend() && (*iter)->getId() != id; ++iter);
    }

    return iter;
}

std::shared_ptr<BaseObject> Scene::getObject(const std::size_t id)
{
    return *getObjectIter(id);
}

std::shared_ptr<Composite> Scene::getVisibleObjects()
{
    return _visibleObjects;
}

std::shared_ptr<Composite> Scene::getInvisibleObjects()
{
    return _invisibleObjects;
}

Iterator Scene::vbegin()
{
    return _visibleObjects->begin();
}

Iterator Scene::vend()
{
    return _visibleObjects->end();
}

Iterator Scene::ibegin()
{
    return _invisibleObjects->begin();
}

Iterator Scene::iend()
{
    return _invisibleObjects->end();
}
