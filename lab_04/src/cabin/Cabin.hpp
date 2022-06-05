
#ifndef LAB_04_CABIN_HPP
#define LAB_04_CABIN_HPP

#include <QObject>
#include <QTimer>

#include "src/defines.hpp"
#include "src/doors/Doors.hpp"

class Cabin : public QObject
{
    Q_OBJECT

    using cabinState = enum {
        WAIT,
        MOVING,
        STOP
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() override = default;

signals:
    void openDoors();
    void updateFloorSignal();
    void readyToMoveSignal();
    void cabinFinished(bool, int=1);

public slots:
    void stopCabin();         // -> WAIT
    void moveCabin();        // -> MOVING
    void free();             // -> STOP

private:
    cabinState _state;
    Doors _doors;
    QTimer _moveTimer;
};


#endif//LAB_04_CABIN_HPP
