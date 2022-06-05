#include "Cabin.hpp"
#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _state = STOP;

    // Сигнал открывания дверей => просим двери открыть двери
    QObject::connect(this, SIGNAL(openDoors()), &_doors, SLOT(startOpening()));

    // Кабина закончила движение => она свободна, выдаём сигнал cabinFinished()
    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(free()));

    // Двери закрылись => кабина освободилась, выдаём сигнал cabinFinished()
    QObject::connect(&_doors, SIGNAL(doorClosed()), this, SLOT(free()));
}

void Cabin::stopCabin()
{
        _state = WAIT;

        _moveTimer.stop();
        emit openDoors(); // signal открыть двери
 }

void Cabin::moveCabin()
{
    if (_state == STOP || _state == MOVING)
    {
        _state = MOVING;
        _moveTimer.start(MOVE_TIME);
    }
}

void Cabin::free()
{
    if (_state != STOP)
    {
        _state = STOP;
        emit cabinFinished(false);
    }
}



