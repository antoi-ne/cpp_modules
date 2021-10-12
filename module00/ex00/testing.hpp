#ifndef TESTING_HPP
#define TESTING_HPP

#include <string>
#include <iostream>
#include <unistd.h>

class testing
{
	private:

	public:
		testing();
		testing(const testing & x);
		virtual ~testing();

		testing& operator=(const testing & x);

};

std::ostream &operator<<(std::ostream &os, testing const &other);

#endif