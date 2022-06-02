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
    MoveModel(const std::shared_ptr<BaseObject> object, const double dx, const double dy, const double dz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> _object;
    double _dx, _dy, _dz;
    Action _method;
};


class ScaleModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &kx, const double &ky, const double &kz);
public:
    ScaleModel(const std::shared_ptr<BaseObject> object, const double kx, const double ky, const double kz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> _object;
    double _kx, _ky, _kz;
    Action _method;
};



class RotateModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &ox, const double &oy, const double &oz);
public:
    RotateModel(const std::shared_ptr<BaseObject> object, const double ox, const double oy, const double oz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> _object;
    double _ox, _oy, _oz;
    Action _method;
};



class TransformModel : public ModelCommand
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const Matrix<double> &mtr);
public:
    TransformModel(const std::shared_ptr<BaseObject> object, const Matrix<double> &mtr);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> _object;
    Matrix<double> _mtr;
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

class AddModel: public ModelCommand
{
    using Action = std::size_t(SceneManager::*)(const shared_ptr<BaseObject> &object);
public:
    AddModel(ID &id, shared_ptr<BaseObject> object);

    virtual void execute() override;
private:
    ID &_id;
    std::shared_ptr<BaseObject> _object;

    Action _method;
};

class LoadModel : public ModelCommand
{
    using Action = std::shared_ptr<BaseObject>(LoadManager::*)(std::string &name);
public:
    LoadModel(std::shared_ptr<BaseObject> &object, std::string &fileName);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> &_object;
    std::string _fileName;

    Action _method;
};

#endif //MODELCOMMAND_H
