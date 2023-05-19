#include "Date.hpp"

Date::Date(void)
    : _year(0), _month(0), _day(0)
{
}

Date::Date(std::string str)
{
    std::stringstream ss(str);
    char dash;

    ss >> this->_year >> dash >> this->_month >> dash >> this->_day;
}

Date::Date(uint year, uint month, uint day)
    : _year(year), _month(month), _day(day)
{
}

Date::Date(Date const &other)
{
    *this = other;
}

Date::~Date(void)
{
}

Date &Date::operator=(Date const &rhs)
{
    if (this != &rhs)
    {
        this->_year = rhs._year;
        this->_month = rhs._month;
        this->_day = rhs._day;
    }
    return *this;
}

std::string Date::toString()
{
    std::stringstream ss;
    ss << this->_year;
    ss << '-';
    ss << this->_month;
    ss << '-';
    ss << this->_day;
    return ss.str();
}

bool Date::operator<(const Date &rhs) const
{
    if (this->_year != rhs._year)
        return this->_year > rhs._year;

    if (this->_month != rhs._month)
        return this->_month > rhs._month;

    return this->_day > rhs._day;
}

std::istream &operator>>(std::istream &is, Date &dt)
{
    uint y, m, d;
    char dash;
    is >> y >> dash >> m >> dash >> d;
    dt = Date(y, m, d);

    return is;
}
