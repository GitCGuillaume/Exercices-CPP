#include "span.hpp"

Span::Span(unsigned int n_value) : N(n_value)
{
}

Span::~Span()
{
}

Span::Span(const Span & cpy) : N(cpy.N)
{
	std::copy(cpy.lst.begin(), cpy.lst.end(), this->lst.begin());
}

Span & Span::operator=(const Span & src)
{
	this->N = src.N;
	std::copy(src.lst.begin(), src.lst.end(), this->lst.begin());
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->N > this->lst.size())
	{
		this->lst.push_back(number);
	}
	else
	{
		throw std::exception();
	}
}

int	Span::shortestSpan(void)
{
	int	substract = 0;

	if (this->lst.size() <= 1)
		throw std::exception();
	substract = this->lst.front();
	for (std::list<int>::iterator it_one = this->lst.begin(); it_one != this->lst.end(); it_one++)
	{
		std::list<int>::iterator it_memory = this->lst.begin();
		while (it_memory != this->lst.end())
		{
			if (*it_memory - *it_one >= 0 && (*it_memory - *it_one) < substract && it_one != it_memory)
			{
				substract = *it_memory - *it_one;
			}
			*it_memory++;
		}
	}
	return (substract);
}

long	Span::longestSpan(void)
{
	long	substract = 0;

	if (this->lst.size() <= 1)
		throw std::exception();
	substract = this->lst.front();
	for (std::list<int>::iterator it_one = this->lst.begin(); it_one != this->lst.end(); it_one++)
	{
		std::list<int>::iterator it_memory = this->lst.begin();
		while (it_memory != this->lst.end())
		{
			if (*it_memory - *it_one >= 0 && (*it_memory - *it_one) > substract && it_one != it_memory)
			{
				substract = *it_memory - *it_one;
			}
			*it_memory++;
		}
	}
	return (substract);
}
