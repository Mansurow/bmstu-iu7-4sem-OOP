#ifndef LAB_04_LIFT_HPP
#define LAB_04_LIFT_HPP

#include <QObject>

#include "src/controller/Controller.hpp"
#include "src/cabin/Cabin.hpp"

class Lift : public QObject
{
    Q_OBJECT

public:
    explicit Lift(QObject *parent = nullptr);
    ~Lift() = default;

    QWidget* widget();

private:
    Controller _controller;
    Cabin _cabin;
};


#endif//LAB_04_LIFT_HPP
