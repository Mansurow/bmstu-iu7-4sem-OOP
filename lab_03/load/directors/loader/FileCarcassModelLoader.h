#ifndef FILLECARCASSMODELLOADER_H
#define FILLECARCASSMODELLOADER_H

#include <fstream>

#include <BaseLoader.h>


class FileCarcassModelLoader : public BaseLoader
{
public:
    FileCarcassModelLoader();
    FileCarcassModelLoader(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t loadCount() override;
    virtual Point loadPoint() override;
    virtual std::vector<Point> loadPoints() override;
    virtual std::vector<Edge> loadEdges(int &amountPoints) override;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILLECARCASSMODELLOADER_H
