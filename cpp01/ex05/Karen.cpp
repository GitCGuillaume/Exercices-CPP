/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:53:03 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/07 16:52:08 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup- burger. I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain( std::string level )
{
	void (Karen::*f)(void);
	int	i;

	i = 0;
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	f = &Karen::error;
	Karen* instance = NULL;
	while (i < 4 && arr[i].compare(level) != 0)
	{
		i++;
	}
	switch (i)
	{
		case 0:
			f = &Karen::debug;
			(instance->*f)();
			break;
		case 1:
			f = &Karen::info;
			(instance->*f)();
			break;
		case 2:
			f = &Karen::warning;
			(instance->*f)();
			break;
		case 3:
			f = &Karen::error;
			(instance->*f)();
			break;
	}
}
