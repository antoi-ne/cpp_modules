#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Fixed
{

	public:

		Fixed(void);
		Fixed(int const i);
		Fixed(float const f);
		Fixed(Fixed const & other);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed & operator=(Fixed const & rhs);

	private:

		int _raw;
		static int const _frac_bits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
