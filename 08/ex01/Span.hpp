
#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

// Class declaration
class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &rhs);
	~Span();
	void addNumber(int number);
	void addNumbers(const std::vector<int> &numbers);
	int shortestSpan() const;
	int longestSpan() const;

private:
	unsigned int _maxSize;
	std::vector<int> _numbers;
};

#endif // SPAN_HPP_
