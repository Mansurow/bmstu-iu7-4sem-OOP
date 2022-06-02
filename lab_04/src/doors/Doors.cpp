#include "Doors.hpp"
#include "../defines.hpp"
#include <QDebug>

Doors::Doors() : _state(CLOSED)
{
    QObject::connect(&_openTimer, SIGNAL(timeout()), this, SLOT(open())); // timeout() - сигнал из qtimer
    QObject::connect(&_waitTimer,  SIGNAL(timeout()), this, SLOT(startClosing()));
    QObject::connect(&_closeTimer, SIGNAL(timeout()), this, SLOT(close()));
}

void Doors::startOpening()
{
    // Если двери не закрыты и не закрываются, то начать открывать её не можем
    if (!(_state == CLOSED || _state == CLOSING)) return;

    this->_state = OPENING;
    qDebug() << "Двери открываются...";

    if (_state == CLOSED)
    {
        this->_openTimer.start(DOOR_TIME);
    }
    else
    {
        auto timer = this->_closeTimer.remainingTime();
        _closeTimer.stop();
        this->_openTimer.start(DOOR_TIME - timer);
    }
}

void Doors::open()
{
    // Если двери до этого не открывались, выходим
    if (this->_state != OPENING) return;

    // Изменение состояния
    this->_state = OPEN;

    qDebug() << "[*] Двери открыты!";

    // Запуск таймера
    this->_waitTimer.start(WAIT_TIME);
}

void Doors::close()
{
    // Если двери до этого не закрывались, выходим
    if (this->_state != CLOSING) return;

    // Изменение состояния
    this->_state = CLOSED;

    qDebug() << "[*] Двери закрылись!";

    // Сообщаем другим, что мы закрылись
    emit doorClosed();
}

void Doors::startClosing()
{
    // Если двери до этого не открыты, закрывать не можем
    if (this->_state != OPEN) return;

    this->_state = CLOSING;

    qDebug() << "Двери закрываются...";

    this->_closeTimer.start(DOOR_TIME);
}
