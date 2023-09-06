/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:56:29 by gchopin           #+#    #+#             */
/*   Updated: 2021/12/20 11:32:54 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

void	ft_list(int search)
{
	std::list<int>			lst;

	lst.push_back(2147483647);
	lst.push_back(-2147483648);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	try
	{
		easyfind(lst, search);
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

void	ft_vector(int search)
{
	std::vector<int>		lst;

	lst.push_back(2147483647);
	lst.push_back(-2147483648);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	try
	{
		easyfind(lst, search);
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

void	ft_deque(int search)
{
	std::deque<int>		lst;

	lst.push_back(2147483647);
	lst.push_back(-2147483648);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	try
	{
		easyfind(lst, search);
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

/*
 ** https://fr.wikibooks.org/wiki/Programmation_C-C%2B%2B/Les_templates/Mot-cl%C3%A9_typename
*/

int	main(void)
{
	ft_list(2147483647);
	ft_list(-2147483648);
	ft_list(1);
	ft_list(4);
	ft_list(2);
	ft_list(3);
	ft_list(5);
	ft_vector(2147483647);
	ft_vector(-2147483648);
	ft_vector(1);
	ft_vector(4);
	ft_vector(2);
	ft_vector(3);
	ft_vector(5);
	ft_deque(2147483647);
	ft_deque(-2147483648);
	ft_deque(1);
	ft_deque(4);
	ft_deque(2);
	ft_deque(3);
	ft_deque(5);
	return (0);
}
