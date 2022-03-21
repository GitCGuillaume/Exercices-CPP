#include "span.hpp"
#include <iostream>

int	main(void)
{
	Span sp = Span(5);
	Span sp2 = Span(10500);
	int	number = -2000;

	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(6);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	for (int i = 0; i < 2000; i++)
	{
		sp2.addNumber(number);
		number++;
	}
	for (int i = 0; i < 2000; i++)
	{
		sp2.addNumber(i + number);
		number++;
	}
	for (int i = 0; i < 2000; i++)
	{
		sp2.addNumber(number);
		number++;
	}
	for (int i = 0; i < 2000; i++)
	{
		sp2.addNumber(number);
		number++;
	}
	for (int i = 0; i < 2500; i++)
	{
		sp2.addNumber(i + number);
		number++;
	}
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
