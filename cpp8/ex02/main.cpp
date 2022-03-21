#include "mutantstack.hpp"
#include <iostream>
#include <algorithm>

void	ft_display(int number)
{
	std::cout << "Number : " << number << std::endl;
}

void	std_cpy(MutantStack<int> mstack)
{
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << std::endl;
	std::stack<int>	s(mstack);
	std::cout << "Display s(copy) std::stack" << std::endl;
	while (s.empty() == false)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	++it;
	--it;
	std::cout << std::endl;
	std::cout << "Iterate mstack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	ft_list(MutantStack<int> mstack)
{
	std::list<int>	lst;

	while (!mstack.empty())
	{
		lst.push_front(mstack.top());
		mstack.pop();
	}
	std::cout << std::endl << "List display" << std::endl;
	std::for_each(lst.begin(), lst.end(), ft_display);
}

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " size : "<< mstack.size() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << " size : "<< mstack.size() << std::endl;
	std::cout << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	for (int i = 0; i < 10; i++)
		mstack.push(i);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Iterate mstack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std_cpy(mstack);
	std::cout << std::endl << "MutantStack copy" << std::endl;
	MutantStack<int>	mstack_cpy(mstack);
	std::for_each(mstack_cpy.begin(), mstack_cpy.end(), ft_display);
	ft_list(mstack);
	return (0);
}
