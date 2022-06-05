#include "Button.hpp"
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressSlot()));
    QObject::connect(this, SIGNAL(unpressSignal()), this, SLOT(unpressSlot())); // Выключается когда лифт приедет и издаст сигнал

    _state = INACTIVE;
    _currentButtonFloor = 1;
}

void Button::setFloor(int floor)
{
    _currentButtonFloor = floor;
}

void Button::pressSlot()
{
    // Если кнопка уже нажата, выходим
    if (this->_state != INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet(QString("background-color:") + COLORBUTTONACTIVE);
    this->update();

    qDebug() << "[!] Вызов на этаж №" << this->_currentButtonFloor;

    // Изменение состояния
    this->_state = ACTIVE;
    this->setDisabled(true);

    // Сигнал всем, что нажата данная кнопка
    emit pressSignal(true, this->_currentButtonFloor);
}

void Button::unpressSlot()
{
    // Если кнопка уже разжата, выходим
    if (this->_state == INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet((QString("background-color:") + COLORBUTTONINACTIVE));
    this->update();

    // Изменение состояния
    this->_state = INACTIVE;
    this->setDisabled(false);
}
