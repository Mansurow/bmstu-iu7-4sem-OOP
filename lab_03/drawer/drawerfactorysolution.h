#ifndef DRAWERFACTORYSOLUTION_H
#define DRAWERFACTORYSOLUTION_H

#include "abstractdrawerfactory.h"
#include "qtdrawerfactory.h"

template <typename Tfactory, typename Tscene>
class DrawerFactorySolution
{
public:
    std::unique_ptr<BaseDrawer> createDrawer(Tscene *scene);
};

#include "drawerfactorysolution.hpp"

#endif // DRAWERFACTORYSOLUTION_H
