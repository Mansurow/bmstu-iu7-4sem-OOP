#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>

#include "basecommand.h"

using ID = std::shared_ptr<std::size_t>;

class ModelCommand : public BaseCommand { };

class MoveModel : public ModelCommand
{
public:
    MoveModel(const double dx, const double dy, const double dz, const std::size_t id);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
};



class ScaleModel : public ModelCommand
{
public:
    ScaleModel(const double kx, const double ky, const double kz, const std::size_t id);

    virtual void execute() override;

private:
    double _kx, _ky, _kz;
    std::size_t _id;
};



class RotateModel : public ModelCommand
{
public:
    RotateModel(const double ox, const double oy, const double oz, const std::size_t id);

    virtual void execute() override;

private:
    double _ox, _oy, _oz;
    std::size_t _id;
};



class TransformModel : public ModelCommand
{
public:
    TransformModel(const Matrix<double> &mtr, const std::size_t id);

    virtual void execute() override;

private:
    Matrix<double> _mtr;
    std::size_t _id;
};



class RemoveModel : public ModelCommand
{
public:
    RemoveModel(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
};



class LoadModel : public ModelCommand
{
public:
    LoadModel(const ID &id, std::string &fileName);

    virtual void execute() override;

private:
    std::string _fileName;
    ID _id;
};

#endif //MODELCOMMAND_H
