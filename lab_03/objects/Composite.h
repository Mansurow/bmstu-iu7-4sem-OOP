#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "BaseObject.h"

class Composite : public BaseObject
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<BaseObject> &element);
    explicit Composite(const std::vector<std::shared_ptr<BaseObject>> &vector);

    virtual bool add(const std::shared_ptr<BaseObject> &element) override;
    virtual bool remove(const Iterator &iter) override;
    virtual void updateCenter() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual Point getCenter() const override;
    virtual void moveElemsToOrigin(const Point &center) override;
    virtual void moveElemsToCenter(const Point &center) override;
    virtual void transformElems(const Matrix<double> &mtr) override;
    virtual void transform(const Matrix<double> &mtr, const Point &center) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    std::vector<std::shared_ptr<BaseObject>> _elements;
};

#endif //COMPOSITE_H
