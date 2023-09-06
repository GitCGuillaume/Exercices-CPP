#include "iter.hpp"
#include <iostream>

void	ftTestOne(int & i)
{
	std::cout << "i = " << i << std::endl;
}

void	ftTestTwo(const char & c)
{
	std::cout << "c = " << c << std::endl;
}

void	ftTestThree(double & d)
{
	d = 1.123456;
}

void	ftTestFour(double const & d)
{
	std::cout << "d = " << d << std::endl;
}

void	ftTestFive(double * d)
{
	*d = 1.123456;
}

template <typename T>
void	ft_template(T const & elem)
{
	std::cout << "template : " << elem << std::endl;
	std::cout << "template : " << &elem << std::endl;
}

int	main(void)
{
	double	arr_two[5] = {0.000000, 0.100000, 0.200000, 0.300000, 0.400000};
	int	arr[5];
	int	i = 0;

	for (i = 0; i < 5; i++)
		arr[i] = i;
	i = 5;
	iter(arr, 5, ftTestOne);
	std::cout << std::endl;
	iter("Bonjour, ceci est un test", 25, ftTestTwo);
	std::cout << std::endl;
	iter(arr_two, 5, ftTestThree);
	iter(arr_two, 5, ftTestFour);
	iter(arr_two, 5, ::ft_template);
	return (0);
}
