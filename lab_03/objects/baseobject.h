#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <memory>
#include <vector>
#include <QDebug>

#include "point.h"


class BaseObject;

using PtrObject = shared_ptr<BaseObject>;
using VectorObjects = vector<PtrObject>;
using Iterator = VectorObjects::const_iterator;

class BaseObject
{
public:
    BaseObject() { _id = _nextId++; };
    virtual ~BaseObject() = default;

    virtual bool add(const PtrObject &) { return false; };
    virtual bool remove(const Iterator &) { return false; };
    virtual void updateCenter() {};

    virtual bool isVisible() { return false; };
    virtual bool isComposite() { return  false; };

    virtual Point getCenter() const = 0;
    virtual void moveElemsToOrigin(const Point &) { }
    virtual void moveElemsToCenter(const Point &) { }
    virtual void transformElems(const Matrix<double> &) { }
    virtual void transform(const Matrix<double> &mtr, const Point &center) = 0;

    virtual void transform(const Coeff &moveCoeff, const Coeff &scaleCoeff, const Coeff &rotateCoeff) = 0;
    virtual void move(const Coeff &moveCoeff) = 0;
    virtual void scale(const Coeff &scaleCoeff) = 0;
    virtual void rotate(const Coeff &rotateCoeff) = 0;

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual std::size_t getId() { return _id; }

protected:
    std::size_t _id;
    static std::size_t _nextId;
};

#endif //BASEOBJECT_H
