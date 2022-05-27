#ifndef BASEADAPTER_H
#define BASEADAPTER_H

class BaseAdapter
{
public:
    virtual ~BaseAdapter() = default;

    virtual void request() = 0;
};

#endif // BASEADAPTER_H
