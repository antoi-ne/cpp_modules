#include "ScalarConvertor.hpp"

const char * ScalarConvertor::InvalidFormatException::what() const throw()
{
	return "format not recognised.";
}

ScalarConvertor::ScalarConvertor(void)
{
}

ScalarConvertor::ScalarConvertor(std::string input)
{
	std::stringstream sts;

	if (ScalarConvertor::isCharFmt(input))
	{
		this->_value = input[1];
	}
	else if (ScalarConvertor::isIntFmt(input))
	{
		sts << input;
		int val = 0;
		sts >> val;
		this->_value = val;
	}
	else if (ScalarConvertor::isFloatFmt(input))
	{
		if (input == "+inff")
			this->_value = INFINITY;
		else if (input == "-inff")
			this->_value = -INFINITY;
		else if (input == "nanf")
			this->_value = NAN;
		else
		{
			input.pop_back();
			sts << input;
			float val = 0;
			sts >> val;
			this->_value = val;
		}
	}
	else if (ScalarConvertor::isDoubleFmt(input))
	{
		if (input == "+inf")
			this->_value = INFINITY;
		else if (input == "-inf")
			this->_value = -INFINITY;
		else if (input == "nan")
			this->_value = NAN;
		else
		{
			sts << input;
			double val = 0;
			sts >> val;
			this->_value = val;
		}
	}
	else
		throw InvalidFormatException();
}

ScalarConvertor::ScalarConvertor(ScalarConvertor const & other)
{
	*this = other;
}

ScalarConvertor::~ScalarConvertor(void)
{
}

ScalarConvertor &ScalarConvertor::operator=(ScalarConvertor const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_value = rhs._value;
	return *this;
}

bool ScalarConvertor::isCharFmt(std::string input)
{
	char c;

	if (input.length() != 3)
		return false;
	if (input[0] != '\'' || input[2] != '\'')
		return false;
	c = input[1];
	if (!std::isprint(c))
		return false;
	return true;
}

bool ScalarConvertor::isIntFmt(std::string input)
{
	std::string cpy(input);

	if (cpy[0] == '-' || cpy[0] == '+')
		cpy = cpy.substr(1);
	for(size_t i = 0; i < cpy.length(); i++)
	{
		if (!std::isdigit(cpy[i]))
			return false;
	}
	long val = std::stol(input, NULL, 10);
	if (val < INT_MIN || val > INT_MAX)
		return false;
	return true;
}

bool ScalarConvertor::isFloatFmt(std::string input)
{
	std::string cpy(input);

	if (input == "+inff" || input == "-inff" || input == "nanf")
		return true;
	if (input[input.length() - 1] != 'f')
		return false;
	cpy.pop_back();
	if (cpy[0] == '-' || cpy[0] == '+')
		cpy = cpy.substr(1);
	if (cpy[0] == '.' || cpy[cpy.length() - 1] == '.' || std::count(cpy.begin(), cpy.end(), '.') != 1 )
		return false;
	for (size_t i = 0; i < cpy.length(); i++)
	{
		if (!isdigit(cpy[i]) && !(cpy[i] == '.'))
			return false;
	}
	return true;
}

bool ScalarConvertor::isDoubleFmt(std::string input)
{
	std::string cpy(input);

	if (input == "+inf" || input == "-inf" || input == "nan")
		return true;
	if (cpy[0] == '-' || cpy[0] == '+')
		cpy = cpy.substr(1);
	if (cpy[0] == '.' || cpy[cpy.length() - 1] == '.' || std::count(cpy.begin(), cpy.end(), '.') != 1 )
		return false;
	for (size_t i = 0; i < cpy.length(); i++)
	{
		if (!isdigit(cpy[i]) && !(cpy[i] == '.'))
			return false;
	}
	return true;
}

char ScalarConvertor::toChar(void)
{
	return static_cast<char>(this->_value);
}

int ScalarConvertor::toInt(void)
{
	return static_cast<int>(this->_value);
}

float ScalarConvertor::toFloat(void)
{
	return static_cast<float>(this->_value);
}

double ScalarConvertor::toDouble(void)
{
	return static_cast<double>(this->_value);
}
