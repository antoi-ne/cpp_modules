#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << "== Testing array creation ==" << std::endl;
	{
		size_t const size = 100;

		Animal *a[size];

		size_t i = 0;
		while (i < size / 2)
			a[i++] = new Dog();
		while (i < size)
			a[i++] = new Cat();

		i = 0;
		while (i < size)
			delete a[i++];
	}
	std::cout << "== Testing copy constructor ==" << std::endl;
	{
		Dog dog;
		
		Dog dog2(dog);

		std::cout << "first dog address: " << &dog.getBrain() << std::endl;
		std::cout << "copy dog address : " << &dog2.getBrain() << std::endl;
	}

	// Animal a("pig"); // not working because a is not instantiable
}