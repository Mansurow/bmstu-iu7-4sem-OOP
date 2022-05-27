#ifndef FILEMODELREADER_H
#define FILEMODELREADER_H

#include <fstream>

#include <baseloader.h>


class FileModelLoader : public BaseLoader
{
public:
    FileModelLoader();
    FileModelLoader(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t loadCount() override;
    virtual Point loadPoint() override;
    virtual Edge loadEdge(int &amountPoints) override;
    virtual std::vector<Point> loadPoints() override;
    virtual std::vector<Edge> loadEdges(int &amountPoints) override;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILEMODELREADER_H
