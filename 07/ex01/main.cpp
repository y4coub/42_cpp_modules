#include "iter.hpp"

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	
	std::cout << "Int array:" << std::endl;
	iter(intArray, 5, print<int>);
	std::cout << "Float array:" << std::endl;
	iter(floatArray, 5, print<float>);
	std::cout << "String array:" << std::endl;
	iter(stringArray, 5, print<std::string>);
	std::cout << "All arrays printed successfully." << std::endl;
	return 0;
}