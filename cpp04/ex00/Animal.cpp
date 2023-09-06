/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:19:16 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 10:15:49 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor created." << std::endl;
}

Animal::Animal(std::string name)
{
	this->type = name;
	std::cout << this->type << " Animal constructor created." << std::endl;
}

Animal::~Animal()
{
	std::cout << this->type << " Animal destructor." << std::endl;
}

Animal::Animal(const Animal & src)
{
	this->type = src.type;
	std::cout << this->type << " Animal copy" << std::endl;
	return ;
}

Animal & Animal::operator=(Animal const & src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " Animal assignation" << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal : " << this->type << " make sound." << std::endl;
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
