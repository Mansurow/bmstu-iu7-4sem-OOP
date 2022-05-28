#include <DrawCompositeAdapter.h>

void DrawCompositeAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCompositeAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

void DrawCompositeAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        for (auto &elem : _adaptee->_elements)
        {
            if (elem->isComposite())
            {
                auto adapter = std::make_shared<DrawCompositeAdapter>(DrawCompositeAdapter());
                auto com_sh_ptr = std::dynamic_pointer_cast<Composite>(elem);
                adapter->setAdaptee(com_sh_ptr);
                adapter->setCamera(_camera);
                adapter->setDrawer(_drawer);
                adapter->request();
            }
            else
            {
                auto adapter = std::make_shared<DrawCarcassModelAdapter>(DrawCarcassModelAdapter());
                auto model_sh_ptr = std::dynamic_pointer_cast<CarcassModel>(elem);
                adapter->setAdaptee(model_sh_ptr);
                adapter->setCamera(_camera);
                adapter->setDrawer(_drawer);
                adapter->request();
            }
        }
    }
}
