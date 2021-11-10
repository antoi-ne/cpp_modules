#ifndef ITER_HPP
#define ITER_HPP

#include <sys/types.h>

template <typename T>
void iter(T *array, size_t len, void (*apply)(T & e))
{
	for (size_t i = 0; i < len; i++)
		apply(array[i]);
}

#endif
