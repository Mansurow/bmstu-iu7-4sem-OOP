#ifndef LAB_04_CONTROLLER_HPP
#define LAB_04_CONTROLLER_HPP

#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <memory>
#include <vector>

#include "src/defines.hpp"
#include "src/button/Button.hpp"

class Controller : public QWidget
{
    Q_OBJECT

    using ControllerState = enum
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() override = default;

signals:
    void stopCabinSignal();
    void moveCabinSignal();
    void reachFloorSignal();

public slots:
    void newTarget(bool ,int = 1);  // -> BUSY
    void reachFloor();              // -> FREE

private:
    bool _identifyNewTarget(int &new_target);
    void _decideDirection();
    void _updateFloor();

private:
    int _curFloor = START_FLOOR;
    int _targetFloor = START_FLOOR;

    Direction _last_direction = STAY;
    Direction _direction = STAY;

    ControllerState _state = FREE;
    std::vector<bool> _is_visit;

    std::vector<std::shared_ptr<Button>> _buttons_floor;
    std::vector<std::shared_ptr<Button>> _buttons_lift;
    std::unique_ptr<QVBoxLayout> _layout;
};

#endif//LAB_04_CONTROLLER_HPP
