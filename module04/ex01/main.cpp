#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << "== Array creation ==" << std::endl;
	{
		size_t const size = 100;

		Animal *a = new Animal[size];

		size_t i = 0;
		while (i < size / 2)
			a[i++] = Dog();
		while (i < size)
			a[i++] = Cat();

		size_t i = 0;
		while (i < size / 2)
			a[i++] = Dog();
		while (i < size)
			a[i++] = Cat();
	}
}