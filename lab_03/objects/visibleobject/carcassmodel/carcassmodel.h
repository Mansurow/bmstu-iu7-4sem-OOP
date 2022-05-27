#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include <memory>
#include <utility>

#include <baseobject.h>
#include <basemodel.h>

#include <point.h>
#include <edge.h>
#include <data.h>

#include <drawcarcassmodeladapter.h>

class CarcassModel : public BaseModel
{
    friend class DrawCarcassModelAdapter;

public:
    CarcassModel() : _data(new Data) { }
    explicit CarcassModel(const std::shared_ptr<Data> &modelStructure) :
        _data(modelStructure) { }
    CarcassModel(const CarcassModel &model);

    ~CarcassModel() override = default;

    virtual Point getCenter() const override;
    virtual void transform(const Matrix<double> &mtr, const Point &center) override;
    virtual void transform(const Coeff &moveCoeff, const Coeff &scaleCoeff, const Coeff &rotateCoeff) override;
    void move(const Coeff &moveCoeff) override;
    void scale(const Coeff &scaleCoeff) override;
    void rotate(const Coeff &rotateCoeff) override;
protected:
    std::shared_ptr<Data> _data;
};


#endif // CARCASSMODEL_H
