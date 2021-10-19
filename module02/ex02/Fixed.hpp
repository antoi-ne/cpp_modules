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

		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;

		Fixed &	operator++(void);
		Fixed &	operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;

		static Fixed &min(Fixed & a, Fixed & b);
		static Fixed &max(Fixed & a, Fixed & b);
		static const Fixed &min(const Fixed & a, const Fixed & b);
		static const Fixed &max(const Fixed & a, const Fixed & b);

	private:

		int _raw;
		static int const _frac_bits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
