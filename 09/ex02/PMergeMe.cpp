#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::~PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &p) {
	_vNumbers.clear();
    _vNumbers.insert(_vNumbers.end(), p._vNumbers.begin(), p._vNumbers.end());
    _dNumbers.clear();
    _dNumbers.insert(_dNumbers.end(), p._dNumbers.begin(), p._dNumbers.end());
}

PMergeMe	&PMergeMe::operator=(const PMergeMe &p) {
    if (this == &p)
		return (*this);
    _vNumbers.clear();
    _vNumbers.insert(_vNumbers.end(), p._vNumbers.begin(), p._vNumbers.end());
    _dNumbers.clear();
    _dNumbers.insert(_dNumbers.end(), p._dNumbers.begin(), p._dNumbers.end());
    return (*this);
}

int	PMergeMe::ftStoi(const char *str){
	int result = 0;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		throw (NegativeInt());
	
	while (*str)
	{
		if (*str < '0' || *str > '9')
			throw (InvalidChar());	
		int digit = *str - '0';
		if (result > (INT_MAX - digit) / 10)
			throw (std::out_of_range("Error: overflow detected."));
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

void	PMergeMe::check(char **av){
	for (int i = 1; av[i]; i++)
	{
		int value = ftStoi(av[i]);
		_vNumbers.push_back(value);
		_dNumbers.push_back(value);
	}
}

void	PMergeMe::sortFJ(char **av) {
	try {
		check(av);

		std::cout << "Before FJ: ";
		for (size_t i = 0; i < _vNumbers.size(); i++)
			std::cout << _vNumbers[i] << " ";
		std::cout << std::endl;
		
		//Vector
		std::clock_t start = std::clock();
		vFordJohnson(_vNumbers);
		std::clock_t stop = std::clock();
		double vTime = ((double)(stop - start) / CLOCKS_PER_SEC * 1000000.0);

		std::cout << "After: ";
		for (size_t i = 0; i < _vNumbers.size(); i++)
			std::cout << _vNumbers[i] << " ";
		std::cout << std::endl;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << _vNumbers.size() << " elements with std::vector : " << vTime << " us." << std::endl;
		
		//Deque
		start = std::clock();
		dFordJohnson(_dNumbers);
		stop = std::clock();
		double dTime = ((double)(stop - start) / CLOCKS_PER_SEC * 1000000.0);
		std::cout << "Time to process a range of " << _dNumbers.size() << " elements with std::deque : " << dTime << " us." << std::endl;
	
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}

std::vector<int> PMergeMe::vGenerateJacobsthalIndices(int n){
	std::vector<int> tmp;
	tmp.push_back(0);
	tmp.push_back(1);
	while (tmp[tmp.size() - 1] < n)
	{
		int next = tmp[tmp.size() - 1] * 2 + tmp[tmp.size() - 2];
		tmp.push_back(next);
	}
	tmp.pop_back();

	std::vector<int> index;
	for (size_t i = 0; i < tmp.size(); i++)
		index.push_back(tmp[i]);
	
	std::vector<bool> used(n, false);
	for (size_t i = 0; i < tmp.size(); i++)
		if (index[i] < n)
			used[index[i]] = true;

	for (int i = 0; i < n; i++)
		if (!used[i])
			index.push_back(i);
	return (index);
}

void	PMergeMe::vFordJohnson(std::vector<int> &v){
	int n = v.size();
	if (n <= 1)
		return;
	
	std::vector<int> max, min;
	max.reserve(n);
	min.reserve(n/2);
	for (int i = 0; i + 1 < n; i += 2)
	{
		if (v[i] > v[i + 1])
		{
			max.push_back(v[i]);
			min.push_back(v[i + 1]);
		}
		else
		{
			max.push_back(v[i + 1]);
			min.push_back(v[i]);
		}
	}
	if (n % 2)
	min.push_back(v[n - 1]);
	
	vFordJohnson(max);
	
	std::vector<int> insertOrder = vGenerateJacobsthalIndices(min.size());
	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		int index = insertOrder[i];
		if (index < (int)min.size())
		{
			std::vector<int>::iterator pos = std::lower_bound(max.begin(), max.end(), min[index]);
			max.insert(pos, min[index]);
		}
	}
	v = max;
}


std::deque<int> PMergeMe::dGenerateJacobsthalIndices(int n){
	std::deque<int> tmp;
	tmp.push_back(0);
	tmp.push_back(1);
	while (tmp[tmp.size() - 1] < n)
	{
		int next = tmp[tmp.size() - 1] * 2 + tmp[tmp.size() - 2];
		tmp.push_back(next);
	}
	tmp.pop_back();

	std::deque<int> index;
	for (size_t i = 0; i < tmp.size(); i++)
		index.push_back(tmp[i]);
	
	std::deque<bool> used(n, false);
	for (size_t i = 0; i < tmp.size(); i++)
		if (index[i] < n)
			used[index[i]] = true;

	for (int i = 0; i < n; i++)
		if (!used[i])
			index.push_back(i);
	return (index);
}

void	PMergeMe::dFordJohnson(std::deque<int> &d){
	int n = d.size();
	if (n <= 1)
		return;
	
	std::deque<int> max, min;

	for (int i = 0; i + 1 < n; i += 2)
	{
		if (d[i] > d[i + 1])
		{
			max.push_back(d[i]);
			min.push_back(d[i + 1]);
		}
		else
		{
			max.push_back(d[i + 1]);
			min.push_back(d[i]);
		}
	}
	if (n % 2)
	min.push_back(d[n - 1]);
	
	dFordJohnson(max);
	
	std::deque<int> insertOrder = dGenerateJacobsthalIndices(min.size());
	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		int index = insertOrder[i];
		if (index < (int)min.size())
		{
			std::deque<int>::iterator pos = std::lower_bound(max.begin(), max.end(), min[index]);
			max.insert(pos, min[index]);
		}
	}
	d = max;
}