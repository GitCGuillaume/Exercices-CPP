#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
void	easyfind(T & a, int & b)
{
	try
	{
		typename T::iterator it;

		it = std::find(a.begin(), a.end(), b);
		if (it != a.end())
			std::cout << "OK" << std::endl;
		else
			throw "KO";
	}
	catch (const char *msg)
	{
		std::cerr << "KO" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

#endif
