#include "iter.hpp"
#include <iostream>

void	ft_test_one(int & i)
{
	std::cout << "i = " << i << std::endl;
}

void	ft_test_two(const char & i)
{
	if (i)
		std::cout << "i = " << i << std::endl;
}

void	ft_test_three(double & i)
{
	std::cout << "i = " << i << std::endl;
}

int	main(void)
{
	double	arr_two[5] = {0.000000, 0.100000, 0.200000, 0.300000, 0.400000};
	int	arr[5];
	int	i = 0;

	for (i = 0; i < 5; i++)
		arr[i] = i;
	i = 5;
	iter(arr, 5, ft_test_one);
	std::cout << std::endl;
	iter("Bonjour, ceci est un test", 25, ft_test_two);
	std::cout << std::endl;
	iter(arr_two, 5, ft_test_three);
	return (0);
}
