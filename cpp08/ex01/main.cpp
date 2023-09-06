#include "span.hpp"
#include <iostream>
#include <vector>

void	range_test()
{
	Span sp2 = Span(12000);
	std::vector<int>	lst;

	for (int i = 10000; i < 40000; i++)
		lst.push_back(i);
	try
	{
		std::cout << "TRY TOO MUCH ELEMENT TO ADD" << std::endl;
		sp2.rangeSpan(lst.begin(), lst.end());
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	lst.clear();
	
	for (int i = 30000; i < 40000; i++)
		lst.push_back(i);
	
	try
	{
		sp2.rangeSpan(lst.begin(), lst.end());
		lst.clear();
		for (int i = 60000; i < 62000; i++)
			lst.push_back(i);
		sp2.rangeSpan(lst.begin(), lst.end());
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TRY ONE MORE ELEMENT OUT OF RANGE" << std::endl;
		lst.clear();
		lst.push_back(1);
		sp2.rangeSpan(lst.begin(), lst.end());
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
}

void	simple_test()
{
	Span sp = Span(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;	
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(6);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;	
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(3);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;	
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(11);
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
int	main(void)
{
	simple_test();
	range_test();
	return (0);
}
