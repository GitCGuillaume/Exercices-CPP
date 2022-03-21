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

Animal::Animal(void)
{
	std::cout << "Animal constructor created." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor." << std::endl;
}

Animal::Animal(const Animal & src)
{
	std::cout << "Animal copy" << std::endl;
	this->type = src.type;
	return ;
}

Animal & Animal::operator=(Animal const & src)
{
	std::cout << "Animal assignation" << std::endl;
	std::cout << "addr this " << this << " addr src " << &src << std::endl;
	if (this != &src)
		this->type = src.type;
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
