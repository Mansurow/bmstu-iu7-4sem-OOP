#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>

#include <BaseCommand.h>

using ID = std::shared_ptr<std::size_t>;

class ModelCommand : public BaseCommand { };

class MoveModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &dx, const double &dy, const double &dz);
public:
    MoveModel(const double dx, const double dy, const double dz, const std::size_t id);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
    Action _method;
};



class ScaleModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &kx, const double &ky, const double &kz);
public:
    ScaleModel(const double kx, const double ky, const double kz, const std::size_t id);

    virtual void execute() override;

private:
    double _kx, _ky, _kz;
    std::size_t _id;
    Action _method;
};



class RotateModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &ox, const double &oy, const double &oz);
public:
    RotateModel(const double ox, const double oy, const double oz, const std::size_t id);

    virtual void execute() override;

private:
    double _ox, _oy, _oz;
    std::size_t _id;
    Action _method;
};



class TransformModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const Matrix<double> &mtr);
public:
    TransformModel(const Matrix<double> &mtr, const std::size_t id);

    virtual void execute() override;

private:
    Matrix<double> _mtr;
    std::size_t _id;
    Action _method;
};



class RemoveModel : public ModelCommand
{
    using Action = void(SceneManager::*)(const size_t id);
public:
    RemoveModel(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
    Action _method;
};



class LoadModel : public ModelCommand
{
    using Action = std::shared_ptr<BaseObject>(LoadManager::*)(std::string &name);
public:
    LoadModel(const ID &id, std::string &fileName);

    virtual void execute() override;

private:
    std::string _fileName;
    ID _id;
    Action _method;
};

#endif //MODELCOMMAND_H
