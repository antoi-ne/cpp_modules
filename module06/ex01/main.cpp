#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data * ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	Data * ptr = new Data();
	uintptr_t serialized = serialize(ptr);
	Data * deserialized = deserialize(serialized);

	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "serialized: " << serialized << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl;

	delete ptr;
	return 0;
}