#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

template<typename T>
class MutantStack: public std::stack<T>
{

	public:

		MutantStack<T>(void): std::stack<T>() {}

		MutantStack<T>(const MutantStack& ref): std::stack<T>(ref) {}

		~MutantStack<T>(void) {}

		MutantStack& operator = (const MutantStack& ref)
		{
			this->c = ref.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

};

#endif