#include <FileCarcassModelLoader.h>
#include <Exceptions.h>


FileCarcassModelLoader::FileCarcassModelLoader()
{
    _file = std::make_shared<std::ifstream>();
}

FileCarcassModelLoader::FileCarcassModelLoader(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void FileCarcassModelLoader::open(std::string &fileName)
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

void FileCarcassModelLoader::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::size_t FileCarcassModelLoader::loadCount()
{
    int count;

    *_file >> count;

    return count;
}

Point FileCarcassModelLoader::loadPoint()
{
    double x, y, z;

    *_file >> x >> y >> z;

    return Point(x, y, z);
}

std::vector<Point> FileCarcassModelLoader::loadPoints()
{
    std::vector<Point> vertexes;

    int vertexNum;
    *_file >> vertexNum;

    if (vertexNum <= 0)
    {
        std::string msg = "wrong vertex num";
        throw SourceException(msg);
    }

    double x, y, z;

    for (int i = 0; i < vertexNum; i++)
    {
       *_file >> x >> y >> z;
       vertexes.push_back(Point(x, y, z));
    }

    return vertexes;
}

std::vector<Edge> FileCarcassModelLoader::loadEdges(int &vertexNum)
{
    std::vector<Edge> links;

    int linksNum;
    *_file >> linksNum;

    if (linksNum <= 0)
    {
        std::string msg = "wrong links num";
        throw SourceException(msg);
    }

    int vertex1Index, vertex2Index;

    for (int i = 0; i < linksNum; i++)
    {
        *_file >> vertex1Index >> vertex2Index;

        if (vertex1Index <= 0 or vertex2Index <= 0 or
            vertex1Index > vertexNum or vertex2Index > vertexNum)
        {
            std::string msg = "wrong link data";
            throw SourceException(msg);
        }

        links.push_back(Edge(vertex1Index, vertex2Index));
    }

    return links;
}
