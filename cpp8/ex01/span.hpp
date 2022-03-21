#include <list>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		std::list<int>	lst;
		unsigned int	N;

	public:
		Span(unsigned int n_value);
		~Span();
		Span(const Span & cpy);
		Span & operator=(const Span & src);
		void	addNumber(int number);
		int	shortestSpan(void);
		long	longestSpan(void);
};
