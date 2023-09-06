#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iostream>

template<typename T>
void	easyfind(T & a, int & b)
{
	typename T::iterator it;

	it = std::find(a.begin(), a.end(), b);
	if (it != a.end())
		std::cout << "OK" << std::endl;
	else
		throw "KO";
}

#endif
