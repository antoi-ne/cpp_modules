#include "CSVParser.hpp"

CSVParser::CSVParser(void)
    : _map()
{
}

CSVParser::CSVParser(std::string path)
    : _map()
{
    std::ifstream is(path);
    std::string header;
    Date dt;
    char sep;
    float fl;

    // skip header
    is >> header;

    std::cout << header << std::endl;

    while (is >> dt >> sep >> fl)
    {
        this->_map[dt] = fl;
    }
}

CSVParser::CSVParser(CSVParser const &other)
{
    *this = other;
}

CSVParser::~CSVParser(void)
{
}

CSVParser &CSVParser::operator=(CSVParser const &rhs)
{
    (void)rhs;
    return *this;
}
