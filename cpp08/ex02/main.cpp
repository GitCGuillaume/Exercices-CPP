#include <list>
#include "mutantstack.hpp"
#include <iostream>
#include <algorithm>

void	ft_display(int number)
{
	std::cout << "Number : " << number << std::endl;
}

void	std_cpy(MutantStack<int> mstack)
{
	MutantStack<int>	s(mstack);
	MutantStack<int>::iterator it = s.begin();
	MutantStack<int>::iterator ite = s.end();

	std::cout << std::endl << "Display s(copy) MutantStack" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	ft_list()
{
	std::list<int>	lst;
	std::list<int>::iterator it;
	std::list<int>::iterator ite;

	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	lst.push_back(0);
	lst.push_back(10);
	lst.push_back(20000);
	lst.push_back(30000);
	it = lst.begin();
	ite = lst.end();
	std::cout << std::endl << "List display" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	ft_reverse_iterate(MutantStack<int>	mstack)
{
	std::cout << std::endl << "Reverse Iterate mstack" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
}

void	ft_iterate(MutantStack<int>	mstack)
{
	std::cout << "Iterate mstack" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " size : "<< mstack.size() << std::endl
		<< "POP" << std::endl;
	mstack.pop();
	std::cout << mstack.top() << " size : "<< mstack.size() << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	for (int i = 0; i < 5; i++)
		mstack.push(i);
	mstack.push(0);
	mstack.push(10);
	mstack.push(20000);
	mstack.push(30000);
	ft_iterate(mstack);
	ft_reverse_iterate(mstack);
	std_cpy(mstack);
	ft_list();
	return (0);
}
