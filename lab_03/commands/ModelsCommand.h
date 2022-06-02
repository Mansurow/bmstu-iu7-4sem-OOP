#ifndef MODELSCOMMAND_H
#define MODELSCOMMAND_H


#include <cstddef>
#include <memory>

#include <BaseCommand.h>


using ID = std::shared_ptr<std::size_t>;

class ModelsCommand : public BaseCommand { };

class MoveModels : public ModelsCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &dx, const double &dy, const double &dz);
public:
    MoveModels(const std::shared_ptr<Composite> objects, const double dx, const double dy, const double dz);

    virtual void execute() override;

private:
    std::shared_ptr<Composite> _objects;
    double _dx, _dy, _dz;
    Action _method;
};



class ScaleModels : public ModelsCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &kx, const double &ky, const double &kz);
public:
    ScaleModels(const std::shared_ptr<Composite> objects, const double kx, const double ky, const double kz);

    virtual void execute() override;

private:
    std::shared_ptr<Composite> _objects;
    double _kx, _ky, _kz;
    Action _method;
};



class RotateModels : public ModelsCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &ox, const double &oy, const double &oz);
public:
    RotateModels(const std::shared_ptr<Composite> objects, const double ox, const double oy, const double oz);

    virtual void execute() override;

private:
    std::shared_ptr<Composite> _objects;
    double _ox, _oy, _oz;
    Action _method;
};



class TransformModels : public ModelsCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const Matrix<double> &mtr);
public:
    TransformModels(const std::shared_ptr<Composite> objects, const Matrix<double> &mtr);

    virtual void execute() override;

private:
    std::shared_ptr<Composite> _objects;
    Matrix<double> _mtr;
    Action _method;
};

#endif // MODELSCOMMAND_H
