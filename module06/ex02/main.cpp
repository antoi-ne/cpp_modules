#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int val = std::rand() % 3;

	switch (val)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		default:
			return new C();
			break;
	}
}

void identify(Base * p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base & p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
	else
		std::cout << "Unknown type" << std::endl;
}

int main(void)
{
	std::srand(std::time(NULL));

	Base * r = generate();

	identify(r);

	return 0;
}