#include "span.hpp"

Span::Span() : N(0)
{
	return ;
}

Span::Span(unsigned int n_value) : N(n_value)
{
	return ;
}

Span::~Span()
{
	return ;
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
		throw std::out_of_range("Out of range, Can't add more number");
	}
}

int	Span::shortestSpan(void)
{
	int	substract = 0;

	if (this->lst.size() <= 1)
		throw std::out_of_range("Out of range");
	std::sort(this->lst.begin(), this->lst.end());
	substract = this->lst.back();
	std::vector<int>::iterator it_two = this->lst.begin();
	for (std::vector<int>::iterator it = this->lst.begin() + 1; it != this->lst.end(); it++)
	{
		it_two = it - 1;
		if (*it - *it_two < substract)
			substract = *it - *it_two;
	}
	return (substract);
}

long	Span::longestSpan(void)
{
	int	substract = 0;

	if (this->lst.size() <= 1)
		throw std::out_of_range("Out of range");
	std::sort(this->lst.rbegin(), this->lst.rend());
	substract = this->lst.front() - this->lst.back();
	return (substract);
}

/* DOIT FAIRE
	Le meilleur pour la fin. Une possibilité qu’il serait utile d’avoir, c’est celle de pouvoir
	remplir votre Span en utilisant une plage d’itérateurs (range of iterators). Faire des
	centaines d’appels à addNumber(), c’est plutôt répétitif. Implémentez une fonction qui
	permet d’ajouter plusieurs nombres à votre Span en un appel.
*/

void	Span::rangeSpan(std::vector<int>::iterator start,
	std::vector<int>::iterator end)
{
	unsigned int	number = std::distance(start, end);

	if (this->N > this->lst.size())
	{
		if (number + this->lst.size() <= this->N)
		{
			this->lst.insert(this->lst.end(), start, end);
		}
		else
		{
			throw std::out_of_range("Out of range, Must add less element");
		}
	}
	else
	{
		throw std::out_of_range("Out of range, Can't add more number");
	}
}