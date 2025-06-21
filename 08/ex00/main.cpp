#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

template <typename T>
void testContainer(T &container, int searchValue, const std::string &containerName)
{
	std::cout << "Searching for value " << searchValue << " in " << containerName << ":" << std::endl;
	try
	{
		typename T::iterator it = easyfind(container, searchValue);
		std::cout << "  ➤ Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "  ✘ Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	// Vector Test
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 2); // 0, 2, 4, ..., 18

	testContainer(vec, 6, "std::vector");
	testContainer(vec, 21, "std::vector");

	// List Test
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);

	testContainer(lst, 10, "std::list");
	testContainer(lst, 3, "std::list");

	// Deque Test
	std::deque<int> deq;
	for (int i = 1; i <= 5; ++i)
		deq.push_back(i * 3); // 3, 6, 9, 12, 15

	testContainer(deq, 12, "std::deque");
	testContainer(deq, 0, "std::deque");

	return 0;
}
