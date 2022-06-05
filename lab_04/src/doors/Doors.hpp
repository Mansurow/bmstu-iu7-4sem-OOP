#ifndef LAB_04_DOORS_HPP
#define LAB_04_DOORS_HPP

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT

    using doorsState = enum {
        OPEN,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    Doors();
    ~Doors() override = default;

signals:
    void doorClosed();

private slots:
    void startClosing();  // -> CLOSING
    void startOpening();  // -> OPENING

public slots:
    void open();          // -> OPEN
    void close();         // -> CLOSED

private:
    doorsState _state;

    QTimer _openTimer;
    QTimer _closeTimer;
    QTimer _waitTimer;
};


#endif//LAB_04_DOORS_HPP
