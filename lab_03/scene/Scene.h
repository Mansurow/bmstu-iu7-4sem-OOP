#ifndef SCENE_H
#define SCENE_H

#include <Composite.h>
#include <Camera.h>
#include <Point.h>

class BaseObject;

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class Scene
{
public:
    Scene();
    ~Scene() = default;

    std::size_t addObject(const std::shared_ptr<BaseObject> &object); // return object id
    std::size_t addCamera(const Point &location);                              // return camera id
    void deleteObject(Iterator &iter);

    Iterator getObjectIter(const std::size_t id);
    std::shared_ptr<BaseObject> getObject(const std::size_t id);
    std::shared_ptr<Composite> getVisibleObjects();
    std::shared_ptr<Composite> getInvisibleObjects();

    Iterator vbegin();
    Iterator vend();

    Iterator ibegin();
    Iterator iend();

protected:
    std::shared_ptr<Composite> _visibleObjects;
    std::shared_ptr<Composite> _invisibleObjects;
};

#endif //SCENE_H
