#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "Date.hpp"

class CSVParser
{

public:
    CSVParser(void);
    CSVParser(std::string path);
    CSVParser(CSVParser const &other);
    virtual ~CSVParser(void);

    CSVParser &operator=(CSVParser const &rhs);

private:
    std::map<Date, float> _map;
};

#endif