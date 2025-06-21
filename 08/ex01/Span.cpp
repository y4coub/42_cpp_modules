#include "Span.hpp"

Span::Span(): _maxSize(0) {}
Span::Span(unsigned int n): _maxSize(n) {}
Span::Span(const Span &other): _maxSize(other._maxSize), _numbers(other._numbers) {}
Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return *this;
}	
Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw std::length_error("Span is full");
	_numbers.push_back(number);
}
void Span::addNumbers(const std::vector<int> &numbers) {
	if (_numbers.size() + numbers.size() > _maxSize)
		throw std::length_error("Span is full");
	_numbers.insert(_numbers.end(), numbers.begin(), numbers.end());
}
int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}
int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}