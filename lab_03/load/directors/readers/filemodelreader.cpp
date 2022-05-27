#include "filemodelreader.h"
#include "exceptions.h"


FileModelLoader::FileModelLoader()
{
    _file = std::make_shared<std::ifstream>();
}

FileModelLoader::FileModelLoader(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void FileModelLoader::open(std::string &fileName)
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(fileName);

    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }
}

void FileModelLoader::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::size_t FileModelLoader::loadCount()
{
    int count;

    *_file >> count;

    return count;
}

Point FileModelLoader::loadPoint()
{
    double x, y, z;

    *_file >> x >> y >> z;

    return Point(x, y, z);
}

std::vector<Point> FileModelLoader::loadPoints()
{
    std::vector<Point> points;

    int amount = loadCount();

    if (amount <= 0)
    {
        std::string msg = "Wrong amount of point! Must > 0!";
        throw SourceException(msg);
    }

    Point curPoint;
    for (int i = 0; i < amount; i++)
    {
        curPoint = loadPoint();
        points.push_back(curPoint);
    }

    return points;
}

Edge FileModelLoader::loadEdge(int &amountPoints)
{
    int first, second;

    *_file >> first >> second;

    if (first <= 0 or second <= 0 or
        first > amountPoints or second > amountPoints)
    {
        std::string msg = "Wrong Data about Edge! Invalid index of Point!";
        throw SourceException(msg);
    }

    return Edge(first, second);
}

std::vector<Edge> FileModelLoader::loadEdges(int &amountPoints)
{
    std::vector<Edge> edges;

    int amount = loadCount();

    if (amount <= 0)
    {
        std::string msg = "wrong links num";
        throw SourceException(msg);
    }

    //int vertex1Index, vertex2Index;
    Edge curEdge;
    for (int i = 0; i < amount; i++)
    {
        curEdge = loadEdge(amountPoints);

        edges.push_back(curEdge);
    }

    return edges;
}
