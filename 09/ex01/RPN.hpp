// RPN.hpp
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <utility>

class RPN {
private:
	std::stack<int, std::list<int> > _stack;

	typedef int (*BinaryOp)(int, int);
	bool hasEnoughOperands() const;
	void applyOperator(BinaryOp op);
	
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	
	void swap(RPN &other);

	void calculate(const std::string &expression);
};

#endif
