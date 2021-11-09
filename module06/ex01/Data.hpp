#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{

	public:

		Data(void);
		Data(Data const & other);
		virtual ~Data(void);

		Data &operator=(Data const & rhs);

	private:

};

#endif