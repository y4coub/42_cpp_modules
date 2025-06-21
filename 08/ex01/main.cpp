#include "Span.hpp"

int main()
{
	// Create a Span object with a size of 5
	Span sp(10);

	// Add some numbers to the Span
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// Print the shortest and longest spans
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// Testing addNumbers with a vector
	std::vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(8);
	numbers.push_back(12);
	numbers.push_back(14);
	sp.addNumbers(numbers);
	std::cout << "After adding numbers from vector:" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// Testing exception handling
	try
	{
		sp.addNumber(20); // This should throw an exception since the Span is full
	}
	catch (const std::length_error &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Span sp2(1);
		sp2.addNumber(5);
		sp2.addNumber(10); // This should throw an exception
	}
	catch (const std::length_error &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}