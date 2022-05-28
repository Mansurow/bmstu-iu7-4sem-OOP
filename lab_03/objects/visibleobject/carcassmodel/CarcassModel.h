#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include <memory>
#include <utility>

#include "BaseObject.h"
#include "basemodel.h"
#include "Point.h"
#include "Edge.h"
#include "Data.h"
#include "drawcarcassmodeladapter.h"

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

protected:
    std::shared_ptr<Data> _data;
};


#endif // CARCASSMODEL_H
