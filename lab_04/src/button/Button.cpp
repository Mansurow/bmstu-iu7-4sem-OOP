#include "Button.hpp"
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(press()));
    QObject::connect(this, SIGNAL(unpressSignal()), this, SLOT(unpress())); // Выключается когда лифт приедет и издаст сигнал

    _state = INACTIVE;
    _curButtonFloor = 1;
}

void Button::setFloor(int floor)
{
    _curButtonFloor = floor;
}

void Button::press()
{
    // Если кнопка уже нажата, выходим
    if (this->_state != INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet("background-color:red");
    this->update();

    qDebug() << "[!] Вызов на этаж №" << this->_curButtonFloor;

    // Изменение состояния
    this->_state = ACTIVE;
    this->setDisabled(true);

    // Сигнал всем, что нажата данная кнопка
    emit pressSignal(true, this->_curButtonFloor);
}

void Button::unpress()
{
    // Если кнопка уже разжата, выходим
    if (this->_state == INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet("background-color:lightblue");
    this->update();

    // Изменение состояния
    this->_state = INACTIVE;
    this->setDisabled(false);
}
