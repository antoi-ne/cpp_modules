#ifndef SCALARCONVERTOR_HPP
#define SCALARCONVERTOR_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConvertor
{

	public:

		class InvalidFormatException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		ScalarConvertor(void);
		ScalarConvertor(std::string input);
		ScalarConvertor(ScalarConvertor const & other);
		virtual ~ScalarConvertor(void);

		ScalarConvertor &operator=(ScalarConvertor const & rhs);

		char toChar(void);
		int toInt(void);
		float toFloat(void);
		double toDouble(void);

	private:

		double _value;

		static bool isCharFmt(std::string input);
		static bool isIntFmt(std::string input);
		static bool isFloatFmt(std::string input);
		static bool isDoubleFmt(std::string input);

};

#endif