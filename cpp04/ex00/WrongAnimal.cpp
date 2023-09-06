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

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor created." << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	this->type = name;
	std::cout << this->type << " WrongAnimal constructor created." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout  << this->type << " WrongAnimal destructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & src)
{
	*this = src;
	std::cout  << this->type << " WrongAnimal copy" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " WrongAnimal assignation created" << std::endl;
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
