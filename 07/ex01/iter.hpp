#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename F>
void print(F const &elem)
{
	std::cout << elem << std::endl;
}

#endif // ITER_HPP