#ifndef DRAWERFACTORYSOLUTION_H
#define DRAWERFACTORYSOLUTION_H

#include <AbstractFactory.h>
#include <QtFactory.h>

template <typename Tfactory, typename Tscene>
class DrawerSolution
{
public:
    std::unique_ptr<BaseDrawer> createDrawer(Tscene *scene);
};

#include <DrawerSolution.hpp>

#endif // DRAWERFACTORYSOLUTION_H
