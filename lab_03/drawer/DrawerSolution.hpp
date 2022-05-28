#ifndef DRAWERSOLUTION_H
#define DRAWERSOLUTION_H

#include <DrawerSolution.h>

template <typename Tfactory, typename Tscene>
std::unique_ptr<BaseDrawer> DrawerSolution<Tfactory, Tscene>::createDrawer(Tscene *scene)
{
    std::shared_ptr<AbstractFactory> factory(new Tfactory(scene));

    return factory->createDrawer();
}


#endif // DRAWERSOLUTION_H
