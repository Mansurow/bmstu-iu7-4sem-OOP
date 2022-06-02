#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <memory>
#include <vector>
#include <QDebug>

#include <Point.h>

class BaseObject;

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class BaseObject
{
public:
    BaseObject() {
        _id = _nextId++;
         //std::cout<< _id << " " << _nextId << std::endl;
    };
    virtual ~BaseObject() = default;

    virtual bool add(const std::shared_ptr<BaseObject> &) { return false; };
    virtual bool remove(const Iterator &) { return false; };
    virtual void updateCenter() {};

    virtual bool isVisible() { return false; };
    virtual bool isComposite() { return  false; };

    virtual Point getCenter() const = 0;
    virtual void moveElemsToOrigin(const Point &) { }
    virtual void moveElemsToCenter(const Point &) { }
    virtual void transformElems(const Matrix<double> &) { }
    virtual void transform(const Matrix<double> &mtr, const Point &center) = 0;

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual std::size_t getId() { return _id; }

protected:
    std::size_t _id;
    static std::size_t _nextId;

    Point _center;
};

#endif //BASEOBJECT_H
