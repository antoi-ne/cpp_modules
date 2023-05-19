#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <istream>

class Date
{

public:
    Date(void);
    Date(std::string str);
    Date(uint year, uint month, uint day);
    Date(Date const &other);
    virtual ~Date(void);

    Date &operator=(Date const &rhs);

    std::string toString();

    bool operator<(const Date &rhs) const;

private:
    uint _year;
    uint _month;
    uint _day;
};

std::istream &operator>>(std::istream &is, Date &dt);

#endif