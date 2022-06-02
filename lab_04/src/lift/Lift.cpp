
#include "Lift.hpp"

Lift::Lift(QObject *parent) : QObject(parent)
{
    _controller.setStyleSheet("background-color:lightblue");

    QObject::connect(&_cabin, SIGNAL(cabinFinished(bool)), &_controller, SLOT(newTarget(bool)));
    QObject::connect(&_controller, SIGNAL(moveCabinSignal()), &_cabin, SLOT(moveCabin()));
    QObject::connect(&_controller, SIGNAL(stopCabinSignal()), &_cabin, SLOT(stopCabin()));
}

QWidget *Lift::widget()
{
    return &_controller;
}
