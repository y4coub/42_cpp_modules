#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <exception>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

class PMergeMe{
	private:
		std::deque<int>		_dNumbers;
		std::vector<int>	_vNumbers;

		void				check(char **av);
		int					ftStoi(const char *str);

		void				vFordJohnson(std::vector<int> &v);
		std::vector<int>	vGenerateJacobsthalIndices(int n); //Which to insert
		void				dFordJohnson(std::deque<int> &d);
		std::deque<int>		dGenerateJacobsthalIndices(int n);

	public:
		PMergeMe();
		~PMergeMe();
		PMergeMe(const PMergeMe &p);
		PMergeMe	&operator=(const PMergeMe &p);

		void				sortFJ(char **av);

		class InvalidChar : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Error: invalid character. Please use only: '0123456789 '");
				}
		};

		class NegativeInt : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("Error: forbidden negative number.");
				}
		};
};

#endif