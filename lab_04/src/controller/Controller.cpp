#include "Controller.hpp"

#include <QLabel>
#include <QDebug>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    this->_layout = std::make_unique<QVBoxLayout>();
    this->setLayout(this->_layout.get());

    auto new_button = std::make_shared<Button>();
    new_button->setDisabled(true);
    new_button->setStyleSheet("background-color:white; color:black");
    new_button->setFloor(FLOORS + 1);
    new_button->setText("Floor Buttons");

    this->_buttons_floor.insert(this->_buttons_floor.begin(), new_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

    for (size_t i = 0; i < FLOORS; i++)
    {

        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));

        this->_buttons_floor.insert(this->_buttons_floor.begin(), new_button);
        _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        _floorsToVisit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(new_button.get(), SIGNAL(pressSignal(bool,int)), this, SLOT(newTarget(bool,int)));
    }

    auto lift_button = std::make_shared<Button>();
    lift_button->setDisabled(true);
    lift_button->setStyleSheet("background-color:white; color:black");
    lift_button->setFloor(2 * FLOORS + 2);
    lift_button->setText("Lift Buttons");
    this->_buttons_lift.insert(this->_buttons_lift.begin(), lift_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(lift_button.get()));


    for (size_t i = 0; i < FLOORS; i++)
    {
        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));

        this->_buttons_lift.insert(this->_buttons_lift.begin(), new_button);
        _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        _floorsToVisit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(new_button.get(), SIGNAL(pressSignal(bool,int)), this, SLOT(newTarget(bool,int)));
    }


    QObject::connect(this, SIGNAL(reachFloorSignal()), this, SLOT(reachFloor()));
}

void Controller::newTarget(bool got_new, int floor)
{
    this->_state = BUSY;
    if (got_new)
    {
        this->_floorsToVisit[floor - 1] = true;

        _identifyNewTarget(floor);
        _targetFloor = floor;
        _decideDirection();
        if (_direction == STAY)
        {
            emit reachFloorSignal();
        }
        else
        {
            emit moveCabinSignal();
        }
    }
    else if (_identifyNewTarget(floor))
    {
        _targetFloor = floor;
        _decideDirection();

        //qDebug() << "direction: " << _direction << "Cur floor" << _curFloor << "Target" << _targetFloor;

        if (_direction != STAY)
        {
            //qDebug() << "HERE!!";
             _updateFloor();
            emit moveCabinSignal();
        }
        else
        {
            emit reachFloorSignal();
        }
     }
}

void Controller::_decideDirection()
{
    if (_targetFloor > _curFloor)
    {
        _direction = UP;
    }
    else if (_targetFloor < _curFloor)
    {
        _direction = DOWN;
    }
    else
    {
        _direction = STAY;
    }
}

bool Controller::_identifyNewTarget(int &new_target)
{
    bool rc = false;

    Direction dir;

    if (_direction != STAY)
    {
        dir = _direction;
    }
    else
    {
        int down_index = 0, top_index = 0;
        for (int i = 0, j = FLOORS - 1; i < (_curFloor - 1) || j > (_curFloor - 1);) {
            if ( i < _curFloor && _floorsToVisit[i])
                down_index = i;
                i ++;

            if (j > _curFloor && _floorsToVisit[j])
                top_index = j;
                j --;
        }

        dir = (((_curFloor - 1) - down_index) < (top_index - (_curFloor - 1))) ? DOWN : UP;
    }

    for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
    {
        if (_floorsToVisit[i - 1])
        {
            new_target = i;
            rc = true;
        }
    }

    if (!rc)
    {
        dir = ((dir == UP) ? DOWN : UP);

        for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
        {
            if (_floorsToVisit[i - 1])
            {
                new_target = i;
                rc = true;
            }
        }
    }

    return rc;
}

void Controller::reachFloor()
{
    // Если контроллер не занят, выходим [лифт не движется]
    if (_state != BUSY) return;

    qDebug() << "[!] Лифт приехал на этаж № " << _targetFloor;

    emit _buttons_floor[_targetFloor - 1]->unpressSignal(); // кнопка разжимается

    emit _buttons_lift[_targetFloor - 1]->unpressSignal(); // кнопка разжимается

    _floorsToVisit[_targetFloor - 1] = false; // посещать его уже не надо


    // проверим, есть ли ещё цели
    if (_identifyNewTarget(_targetFloor))
    {
        emit stopCabinSignal();
    }
    else
    {
        // Целей нет
        _state = FREE; // Контроллер освободился
        emit stopCabinSignal();
    }
}

void Controller::_updateFloor()
{
    _curFloor += _direction;

     qDebug() << "... Лифт едет на этаж № " << _curFloor;
}
