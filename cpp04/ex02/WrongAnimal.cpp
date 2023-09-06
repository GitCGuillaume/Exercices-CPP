/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:19:16 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 10:12:37 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor created." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & src)
{
	std::cout << "WrongAnimal copy" << std::endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal : " << this->type << " make sound." << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
