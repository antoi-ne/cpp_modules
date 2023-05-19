#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>

class BitcoinExchange
{

	public:

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & other);
		virtual ~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const & rhs);

	private:

};

#endif