#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "baseobject.h"

class Composite : public BaseObject
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(PtrObject &object);
    explicit Composite(const VectorObjects &vector);

    virtual bool add(const PtrObject &object) override;
    virtual bool remove(const Iterator &iter) override;
    virtual void updateCenter() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual Point getCenter() const override;
    virtual void moveElemsToOrigin(const Point &center) override;
    virtual void moveElemsToCenter(const Point &center) override;
    virtual void transformElems(const Matrix<double> &mtr) override;
    virtual void transform(const Matrix<double> &mtr, const Point &center) override;

    virtual void transform(const Coeff &moveCoeff, const Coeff &scaleCoeff, const Coeff &rotateCoeff) override;
    virtual void move(const Coeff &moveCoeff) override;
    virtual void scale(const Coeff &scaleCoeff) override;
    virtual void rotate(const Coeff &rotateCoeff) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    Point _center;
    VectorObjects _objects;
};

#endif //COMPOSITE_H
