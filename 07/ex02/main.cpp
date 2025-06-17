#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror; //
// 	return 0;
// }


#include <iostream>
#include "Array.hpp"

void printArray(const Array<int> &arr, const std::string &label)
{
	std::cout << label << ": ";
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i * 10;

	printArray(a, "Original");

	// Copy constructor
	Array<int> b(a);
	printArray(b, "Copy constructed");

	// Assignment operator
	Array<int> c;
	c = a;
	printArray(c, "Assigned");

	// Modify and verify deep copy
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i * 100 + 999;
	printArray(a, "Original after modifying copy");
	printArray(b, "Modified copy");

	// Exception tests
	try {
		a[a.size()] = 100; // Invalid: index out of bounds
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		a[-1] = 100; // Invalid: negative index (converted to huge unsigned int)
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
// Output:
// Original: 0 10 20 30 40
// Copy constructed: 0 10 20 30 40
// Assigned: 0 10 20 30 40
// Modified copy: 999 10 20 30 40
// Original after modifying copy: 0 10 20 30 40
// Exception caught: Index is out of bounds
// Exception caught: Index is out of bounds