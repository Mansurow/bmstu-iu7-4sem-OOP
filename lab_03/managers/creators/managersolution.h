#ifndef CREATEMANAGERSOLUTION_H
#define CREATEMANAGERSOLUTION_H

#include <memory>

template<typename Tcreator>
class ManagerSolution
{
public:
    decltype(auto) create();
};

template<typename Tcreator>
decltype(auto) ManagerSolution<Tcreator>::create()
{
    auto creator = Tcreator();
    auto manager = creator.createManager();

    return manager;
}

#endif // CREATEMANAGERSOLUTION_H
