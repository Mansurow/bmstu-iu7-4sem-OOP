#include <QDebug>

#include "modelloadmoderator.h"
#include "exceptions.h"
#include "modelbuilder.h"


ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelDirector> director) :
    _builder(new ModelBuilder)
{
    _director = director;
}


std::shared_ptr<BaseObject> ModelLoadModerator::load(std::string &fileName)
{
    std::shared_ptr<CarcassModel> model_sh_ptr;

    try
    {
        model_sh_ptr = _director->load(_builder, fileName);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }
    catch (std::exception &error)
    {
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    return std::shared_ptr<BaseObject>(model_sh_ptr);
}
