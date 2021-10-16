#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Fixed
{

	public:

		Fixed(void);
		Fixed(Fixed const & other);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed & operator=(Fixed const & rhs);

	private:

		int _number;
		static const int _fraction_bits;
};

// std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
