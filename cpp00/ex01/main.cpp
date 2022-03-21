/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:37:28 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/14 17:26:13 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

void	ft_search_index(PhoneBook *phonebook, unsigned int i)
{
	std::string str;
	size_t	find;
	unsigned int	idx = 0;

	std::cout << "Enter an index to get coordonates." << std::endl;
	std::getline(std::cin, str);
	find = str.find_first_of("12345678");
	std::istringstream(str) >> idx;
	if (str.length() == 1 && find == 0 && idx <= i && phonebook->getContact(idx - 1))
	{
		std::cout << "Index : " << phonebook->getContact(idx - 1)->getIndex() << std::endl;
		std::cout << "First name : " << phonebook->getContact(idx - 1)->getFirstName() << std::endl;
		std::cout << "Last name : " << phonebook->getContact(idx - 1)->getLastName() << std::endl;
		std::cout << "Nickname : " << phonebook->getContact(idx - 1)->getNickname() << std::endl;
		std::cout << "Phone number : " << phonebook->getContact(idx - 1)->getPhoneNumber() << std::endl;
	}
	else
		std::cout << "Index is wrong..." << std::endl;
}

void	ft_search(PhoneBook *phonebook, unsigned int i)
{
	std::string first;
	std::string last;
	std::string nickname;

	std::cout << std::setw(10) << std::right << "Index" << '|' 
		<< std::setw(10) << std::right << "First Name" << '|'
		<< std::setw(10) << std::right << "Last Name" << '|'
		<< std::setw(10) << std::right << "Nickname" << '|'
		<< std::endl;
	for (unsigned int j = 0; i > j; j++)
	{
		if (phonebook->getContact(j))
		{
			first.append(phonebook->getContact(j)->getFirstName());
			if (first.length() > 10)
			{
				first.replace(9, 10, ".");
				first.resize(10);
			}
			last.append(phonebook->getContact(j)->getLastName());
			if (last.length() > 10)
			{
				last.replace(9, 10, ".");
				last.resize(10);
			}
			nickname.append(phonebook->getContact(j)->getNickname());
			if (nickname.length() > 10)
			{
				nickname.replace(9, 10, ".");
				nickname.resize(10);
			}
			std::cout << std::setw(10) << std::right << phonebook->getContact(j)->getIndex() << '|' 
				<< std::setw(10) << std::right << first << "|"
				<< std::setw(10) << std::right << last << "|"
				<< std::setw(10) << std::right << nickname << "|"
				<< std::endl;
			first.clear();
			last.clear();
			nickname.clear();
		}
	}
	ft_search_index(phonebook, i);
}

void	ft_add(PhoneBook *phonebook, unsigned int i)
{
	std::string str;

	if (!phonebook->getContact(i))
		return ;
	std::cout << "Enter first name : " << std::endl;
	while (getline(std::cin >> std::ws, str))
	{
		if (str.empty() == false)
			break ;
	}
	phonebook->getContact(i)->setFirstName(str);
	str.clear();
	std::cout << "First name is : " + phonebook->getContact(i)->getFirstName() << std::endl;
	
	std::cout << "Enter last name : " << std::endl;
	while (getline(std::cin >> std::ws, str))
	{
		if (str.empty() == false)
			break ;
	}
	phonebook->getContact(i)->setLastName(str);
	str.clear();
	std::cout << "Last name is : " + phonebook->getContact(i)->getLastName() << std::endl;
	
	std::cout << "Enter nickname : " << std::endl;
	while (getline(std::cin >> std::ws, str))
	{
		if (str.empty() == false)
			break ;
	}
	phonebook->getContact(i)->setNickname(str);
	str.clear();
	std::cout << "Nickname is : " + phonebook->getContact(i)->getNickname() << std::endl;

	std::cout << "Enter phone number : " << std::endl;
	while (getline(std::cin >> std::ws, str))
	{
		if (str.empty() == false)
			break ;
	}
	phonebook->getContact(i)->setPhoneNumber(str);
	str.clear();
	std::cout << "Phone number is : " + phonebook->getContact(i)->getPhoneNumber() << std::endl;
	
	std::cout << "Enter darkest secret : " << std::endl;
	while (getline(std::cin >> std::ws, str))
	{
		if (str.length() == 0)
			std::cout << "Input must not be empty" << std::endl;
		else
			break ;
	}
	phonebook->getContact(i)->setDarkestSecret(str);
	phonebook->getContact(i)->setIndex(i + 1);
}

int	main(void)
{
	PhoneBook phonebook;
	std::string str;
	unsigned int	i;
	unsigned int	number;

	i = 0;
	number = 0;
	std::cout << "Please enter a command..." << std::endl;
	while (getline(std::cin, str))
	{
		if (str == "EXIT")
			return (0);
		else if (str == "ADD" && i < 8 && str.length() <= 3)
		{
			ft_add(&phonebook, i);
			i += 1;
			if (i <= 8 && number < 8)
				number += 1;
			if (i >= 8)
				i = 0;
		}
		else if (str == "SEARCH")
			ft_search(&phonebook, number);
		std::cout << "Please enter a command..." << std::endl;
	}
	return (0);
}
