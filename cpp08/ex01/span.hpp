#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		std::vector<int>	lst;
		unsigned int	N;

	public:
		Span();
		Span(unsigned int n_value);
		~Span();
		Span(const Span & cpy);
		Span & operator=(const Span & src);
		void	addNumber(int number);
		int		shortestSpan(void);
		long	longestSpan(void);
		void	rangeSpan(std::vector<int>::iterator start, std::vector<int>::iterator end);
};
